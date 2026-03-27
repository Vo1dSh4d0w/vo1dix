#include <stdarg.h>
#include <stdio.h>

int fprintf(FILE *file, const char *restrict format, ...) {
    int ret;
    va_list ap;
    
    va_start(ap, format);
    
    ret = vfprintf(file, format, ap);
    
    va_end(ap);
    return ret;
}