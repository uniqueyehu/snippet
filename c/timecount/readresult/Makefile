obj-m := readcount.o

.PHONY: all clean

KERNELDIR := /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) clean
	$(MAKE) -C $(KERNELDIR) SUBDIRS=$(shell pwd) modules

clean:
	rm .*.cmd -rf
	rm .tmp* -rf
	rm *.o -rf
	rm *.mod.* -rf
	rm *.ko -rf
	@rm *.symvers -f
	@rm *.order -f
	echo "Delete output files"
