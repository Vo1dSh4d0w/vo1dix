#include <kernel/debug.h>
#include <stdarg.h>
#include <stdio.h>
#include "serial.h"

void kdprintf(char *restrict format, ...) {
    char buf[1024];
    va_list ap;
    int i;
    
    va_start(ap, format);
    
    vsnprintf(buf, 1024, format, ap);
    
    for (i = 0; buf[i]; i++) {
        serial_write(buf[i]);
    }
}