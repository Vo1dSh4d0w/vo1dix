#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>

static int write(char *str) {
    int l;
    for (l = 0; str[l]; l++) {
        putchar(str[l]);
    }
    return l;
}

static void itoa(char *buf, int i, int base) {
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

int printf(const char *restrict format, ...) {
    int len = 0, d;
    char *str, buf[32], c;
    va_list ap;
    va_start(ap, format);
    
    while (format[0]) {
        if (format[0] == '%') {
            format++;
            switch (format[0]) {
                case 'c':
                c = va_arg(ap, int);
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
                d = va_arg(ap, int);
                itoa(buf, d, 16);
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
    
    return len;
}
