#ifndef _KERNEL_KMALLOC_H
#define _KERNEL_KMALLOC_H

#include <stddef.h>
#include <stdint.h>

void heap_init(uintptr_t heap_start, uintptr_t heap_end);

void *kmalloc(size_t n);

#endif