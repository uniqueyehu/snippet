# object name -- timecount
obj-m := timecount.o
# some .o timecount contained
#timecount-objs := 1xxx.o 2xxxx.o

.PHONY: all clean

# kernel Makefile directroy
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