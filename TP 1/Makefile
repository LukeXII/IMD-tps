
obj-m += hello_version.o

KERNEL_DIR ?= /home/lucas/IMD/buildroot/output/build/linux-custom

all:

	make -C $(KERNEL_DIR) \
	ARCH=arm64 CROSS_COMPILE=aarch64-buildroot-linux-gnu- \
	M=$(PWD) modules

clean:

	make -C $(KERNEL_DIR) \
	ARCH=arm64 CROSS_COMPILE=aarch64-buildroot-linux-gnu- \
	M=$(PWD) clean

#deploy:

	scp *.ko root@:192.168.137.51:root
