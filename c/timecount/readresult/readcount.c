#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

//#include <linux/interrupt.h>
//#include <linux/hrtimer.h>
//#include <linux/ktime.h>

#include <linux/fs.h>
#include <linux/uaccess.h>

static loff_t rf = 0;

void read_result()
{
	struct file *fp = 0;
	mm_segment_t fs = get_fs();
	int ret = 0;
	long err = 0;
	long long delta = 0;
	int i = 0;
	long long sum = 0;

	set_fs(KERNEL_DS);
	fp = filp_open("/raid/time_result", O_RDONLY, 0);
	//fp = filp_open("/home/yehu/mymodules/time_result", O_RDONLY, 0);
	if ((err = IS_ERR(fp)))
		printk("open file 2 error !!!!!!!!!!!11\n");
/*
	for (i = 0; i < 10; ++i) {
		ret = vfs_read(fp, &delta, sizeof(delta), &rf);
		if (ret < 0)
			printk("vfs_read error !!!!!!!!!!!!!!!\n");
		printk("read is %lld \n", delta);
	}
*/
	// 读到文件尾，会返回0，作为结束条件
	while((ret = vfs_read(fp, &delta, sizeof(delta), &rf)))
	{
		//printk("read is %lld \n", delta);
		sum += delta;
		++i;
	}
	printk("i = %d, sum = %lld\n", i, sum/i);

	filp_close(fp, 0);
	set_fs(fs);
}

int readcount_init(void)
{
	printk("*************************\n");
	printk("Hello world!\n");
	printk("*************************\n");

	read_result();

	return 0;
}

void readcount_exit(void)
{
	printk("+++++++++++++++++++++++++\n");
	printk("Bye world!\n");
	printk("+++++++++++++++++++++++++\n\n");
}

module_init(readcount_init);
module_exit(readcount_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("yehu");
