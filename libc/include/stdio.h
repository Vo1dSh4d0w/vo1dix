#ifndef _LIBC_STDIO_H
#define _LIBC_STDIO_H

#include <stdarg.h>
#include <stddef.h>

int putchar(int c);

int printf(const char *restrict format, ...);
int snprintf(char *restrict str, size_t size, const char *restrict format, ...);

int vprintf(const char *restrict format, va_list ap);
int vsnprintf(char *restrict str, size_t size, const char *restrict format, va_list ap);

#endif