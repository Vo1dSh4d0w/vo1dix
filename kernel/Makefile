TARGET_ARCH?=i686

CFLAGS:=$(CFLAGS) -ffreestanding -Wall -Wextra -Iinclude
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -nostdlib -lgcc -lk

ARCH_SOURCE=arch/$(TARGET_ARCH)

include $(ARCH_SOURCE)/make.config

KERNEL_OBJS=\
$(KERNEL_ARCH_OBJS) \
kernel.o \

OBJS=\
$(ARCH_SOURCE)/crti.o \
$(ARCH_SOURCE)/crtbegin.o \
$(KERNEL_OBJS) \
$(ARCH_SOURCE)/crtend.o \
$(ARCH_SOURCE)/crtn.o \

.PHONY: all clean install install-kernel install-headers
.SUFFIXES: .o .c .S

all: vo1dix.kernel

vo1dix.kernel: $(OBJS) $(ARCH_SOURCE)/linker.ld
	$(CC) -T $(ARCH_SOURCE)/linker.ld -o $@ $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIBS)
	
$(ARCH_SOURCE)/crtbegin.o $(ARCH_SOURCE)/crtend.o:
	OBJ=`$(CC) $(CFLAGS) $(LDFLAGS) -print-file-name=$(@F)` && cp "$$OBJ" $@

.c.o:
	$(CC) -c $< -o $@ --std=gnu11 $(CFLAGS)

.S.o:
	$(CC) -c $< -o $@ $(CFLAGS)
	
install: install-headers install-kernel
	
install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R include/* $(DESTDIR)$(INCLUDEDIR)
	
install-kernel: vo1dix.kernel
	mkdir -p $(DESTDIR)$(BOOTDIR)
	cp vo1dix.kernel $(DESTDIR)$(BOOTDIR)

clean:
	rm -f $(OBJS) vo1dix.kernel
