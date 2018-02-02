#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

// ktime_t 相关结构和函数
#include <linux/interrupt.h>
#include <linux/hrtimer.h>
#include <linux/ktime.h>

// 内核文件读写
#include <linux/fs.h>
#include <linux/uaccess.h>

// 文件读写指针
//static loff_t rf = 0;
static loff_t wf = 0;

void func()
{
	int i;
	int j;
	for (i = 0; i < 1000; ++i)
		for (j = 0; j < 1000; ++j)
			;
}

void time_result()
{
	struct file *xfp = 0;
	mm_segment_t xfs = get_fs();
	int ret = 0;
	long err = 0;
	long long delta = 0;

	ktime_t start, end;

	// switch to kernel space
	set_fs(KERNEL_DS);
	xfp = filp_open("/home/yehu/mymodules/time_result", O_RDWR|O_CREAT, 0);
	if ((err = IS_ERR(xfp)))
		printk("open time_result file error !!!!!!!!\n");
	
	start = ktime_get();
	func();
	end = ktime_get();
	delta = (long long) ktime_to_ns(ktime_sub(end, start));

	printk("running time is %lld ns\n", delta);

	//xfp->f_pos = 0;
	ret = vfs_write(xfp, (char *) &delta, sizeof(delta), &wf);
	if (ret < 0)
		printk("vfs_write file error %d!!!!!!!!!!!!!!!\n", ret);

	filp_close(xfp, 0);
	set_fs(xfs);	// back to user space
	return ;
}

int timecount_init(void)
{
	printk("*************************\n");
	printk("Hello world!\n");
	printk("*************************\n");

	int iter;
	for (iter = 0; iter < 15; ++iter)
		time_result();

	return 0;
}

void timecount_exit(void)
{
	printk("+++++++++++++++++++++++++\n");
	printk("Bye world!\n");
	printk("+++++++++++++++++++++++++\n\n");
}

module_init(timecount_init);
module_exit(timecount_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("yehu");
