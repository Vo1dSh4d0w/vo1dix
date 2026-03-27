#ifndef _LIBC_STDIO_H
#define _LIBC_STDIO_H

#include <stdarg.h>
#include <stddef.h>

typedef struct _FILE FILE;

struct _FILE {
    void *device;
    void (*write)(FILE *f, const char *restrict str, size_t len);
};

extern FILE *stdout;

int putchar(int c);

int printf(const char *restrict format, ...) __attribute__((format (printf, 1, 2)));
int fprintf(FILE *file, const char *restrict format, ...) __attribute__((format (printf, 2, 3)));
int snprintf(char *restrict str, size_t size, const char *restrict format, ...) __attribute__((format (printf, 3, 4)));

int vprintf(const char *restrict format, va_list ap);
int vfprintf(FILE *file, const char *restrict format, va_list ap);
int vsnprintf(char *restrict str, size_t size, const char *restrict format, va_list ap);

#endif