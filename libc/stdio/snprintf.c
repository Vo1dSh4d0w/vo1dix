#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>

int snprintf(char *restrict str, size_t size, const char *restrict format, ...) {
    va_list ap;
    int ret;
    
    va_start(ap, format);
    
    ret = vsnprintf(str, size, format, ap);
    
    va_end(ap);
    
    return ret;
}