#include <kernel/debug.h>
#include <stdarg.h>
#include <stdio.h>
#include "serial.h"

void kdprintf(char *restrict format, ...) {
    va_list ap;
    va_start(ap, format);
    
    vfprintf(serial_out, format, ap);
    va_end(ap);
}