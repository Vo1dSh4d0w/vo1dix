#ifndef _LIBC_STRING_H
#define _LIBC_STRING_H

#include <stddef.h>

void *memset(void *s, int c, size_t n);
void *memmove(void *dest, const void *src, size_t n);

size_t strlen(const char *s);

#endif