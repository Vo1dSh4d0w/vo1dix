#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#ifdef __IS_LIBK
#include <kernel/terminal.h>
#endif


int vfprintf(FILE *file, const char *restrict format, va_list ap) {
    uint8_t lflag, llflag;
    int len = 0, i;
    unsigned int u;
    long l;
    long long ll;
    unsigned long ul;
    unsigned long long ull;
    size_t le;
    char *str, buf[32], c;

    while (format[0]) {
        if (format[0] == '%') {
            format++;
            
            if (format[0] == '\0') break;
            
            lflag = llflag = 0;
            if (format[0] == 'l') {
                format++;
                if (format[0] == 'l') {
                    llflag = 1;
                    format++;
                } else {
                    lflag = 1;
                }
            }
            
            switch (format[0]) {
                case 'c':
                c = va_arg(ap, int);
                file->write(file, &c, 1);
                len++;
                break;
                case 's':
                str = va_arg(ap, char*);
                le = strlen(str);
                file->write(file, str, le);
                len += le;
                break;
                case 'd':
                if (llflag) {
                    ll = va_arg(ap, long long);
                    lltoa(buf, ll, 10);
                } else if (lflag) {
                    l = va_arg(ap, long);
                    ltoa(buf, l, 10);
                } else {
                    i = va_arg(ap, int);
                    itoa(buf, i, 10);
                }
                le = strlen(buf);
                file->write(file, buf, le);
                len += le;
                break;
                case 'x':
                if (llflag) {
                    ull = va_arg(ap, unsigned long long);
                    ulltoa(buf, ull, 16);
                } else if (lflag) {
                    ul = va_arg(ap, unsigned long);
                    ultoa(buf, ul, 16);
                } else {
                    u = va_arg(ap, unsigned int);
                    utoa(buf, u, 16);
                }
                le = strlen(buf);
                file->write(file, buf, le);
                len += le;
                break;
                case '%':
                file->write(file, "%", 1);
                len++;
                break;
                default:
                file->write(file, format - (1 + llflag * 2 + lflag), 2 + llflag * 2 + lflag);
                len += 2 + llflag * 2 + lflag;
                break;
            }
            format++;
        } else {
            file->write(file, format, 1);
            len++;
            format++;
        }
    }

#ifdef __IS_LIBK
    terminal_update_cursor(&tty0);
#endif

    return len;
}