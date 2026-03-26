#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

int printf(const char *restrict format, ...) {
    va_list ap;
    int ret;
    
    va_start(ap, format);
    
    ret = vprintf(format, ap);
    
    va_end(ap);
    return ret;
}
