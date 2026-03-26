#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#ifdef __IS_LIBK
#include <kernel/terminal.h>
#endif

static int write(char *str) {
    int l;
    for (l = 0; str[l]; l++) {
        putchar(str[l]);
    }
    return l;
}

static void itoa(char *buf, int64_t i, int base) {
    unsigned int ui = i, rem;
    char *ptr = buf, *left, *right, tmp;

    if (i < 0) {
        *ptr++ = '-';
        buf++;
        ui = -i;
    }

    do {
        rem = ui % base;
        *ptr++ = rem < 10 ? '0' + rem : 'a' + rem - 10;
    } while (ui /= base);

    *ptr = 0;
    left = buf;
    right = ptr - 1;

    while (left < right) {
        tmp = *left;
        *left = *right;
        *right = tmp;

        left++;
        right--;
    }
}

static void utoa(char *buf, uint64_t i, int base) {
    unsigned int rem;
    char *ptr = buf, *left, *right, tmp;

    do {
        rem = i % base;
        *ptr++ = rem < 10 ? '0' + rem : 'a' + rem - 10;
    } while (i /= base);

    *ptr = 0;
    left = buf;
    right = ptr - 1;

    while (left < right) {
        tmp = *left;
        *left = *right;
        *right = tmp;

        left++;
        right--;
    }
}

int printf(const char *restrict format, ...) {
    int len = 0;
    int64_t d;
    uint64_t u;
    char *str, buf[32], c;
    va_list ap;
    va_start(ap, format);

    while (format[0]) {
        if (format[0] == '%') {
            format++;
            switch (format[0]) {
                case 'c':
                c = va_arg(ap, int64_t);
                putchar(c);
                len++;
                break;
                case 's':
                str = va_arg(ap, char*);
                len += write(str);
                break;
                case 'd':
                d = va_arg(ap, int);
                itoa(buf, d, 10);
                len += write(buf);
                break;
                case 'x':
                u = va_arg(ap, uint64_t);
                utoa(buf, u, 16);
                len += write(buf);
                break;
                case '%':
                putchar('%');
                len++;
                break;
            }
            format++;
        } else {
            putchar(format[0]);
            len++;
            format++;
        }
    }

#ifdef __IS_LIBK
    terminal_update_cursor(&tty0);
#endif

    return len;
}
