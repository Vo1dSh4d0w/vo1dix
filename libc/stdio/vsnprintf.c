#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>

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

int vsnprintf(char *str, size_t size, const char *restrict format, va_list ap) {
    size_t len = 0, sidx;
    int64_t d;
    uint64_t u;
    char *s, buf[32], c;

    while (format[0]) {
        if (format[0] == '%') {
            format++;
            switch (format[0]) {
                case 'c':
                c = va_arg(ap, int);
                if (len + 1 >= size) {
                    goto vsnprintf_end;
                }
                str[len++] = c;
                break;
                case 's':
                s = va_arg(ap, char*);
                for (sidx = 0; s[sidx]; sidx++) {
                    if (len + 1 >= size) {
                        goto vsnprintf_end;
                    }
                    str[len++] = s[sidx];
                }
                break;
                case 'd':
                d = va_arg(ap, int64_t);
                itoa(buf, d, 10);
                for (sidx = 0; buf[sidx]; sidx++) {
                    if (len + 1 >= size) {
                        goto vsnprintf_end;
                    }
                    str[len++] = buf[sidx];
                }
                break;
                case 'x':
                u = va_arg(ap, uint64_t);
                utoa(buf, u, 16);
                for (sidx = 0; buf[sidx]; sidx++) {
                    if (len + 1 >= size) {
                        goto vsnprintf_end;
                    }
                    str[len++] = buf[sidx];
                }
                break;
                case '%':
                if (len + 1 >= size) {
                    goto vsnprintf_end;
                }
                str[len++] = '%';
                break;
            }
            format++;
        } else {
            if (len + 1 >= size) {
                goto vsnprintf_end;
            }
            str[len++] = format[0];
            format++;
        }
    }
    vsnprintf_end:
    if (size > 0) {
        str[len] = 0;
    }

    return len;
}