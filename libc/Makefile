CFLAGS?=
LDFLAGS?=
LIBS?=

LIBK_CFLAGS=$(CFLAGS) -D__IS_LIBK

LIBC_OBJS=\
ctype/isprint.o \
stdio/putchar.o \
string/memset.o \
string/strlen.o

LIBK_OBJS=$(LIBC_OBJS:.o=.libk.o)

.PHONY: all clean install install-headers install-libs
.SUFFIXES: .o .libk.o .c

all: libk.a

libk.a: $(LIBK_OBJS)
	$(AR) rcs $@ $(LIBK_OBJS)

.c.libk.o:
	$(CC) -c $< -o $@ -std=gnu11 $(LIBK_CFLAGS)

clean:
	rm -f libk.a
	rm -f $(OBJS) $(LIBK_OBJS)

install: install-headers install-libs

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R include/* $(DESTDIR)$(INCLUDEDIR)

install-libs: libk.a
	mkdir -p $(DESTDIR)$(LIBDIR)
	cp libk.a $(DESTDIR)$(LIBDIR)
