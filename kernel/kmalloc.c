#include <kernel/debug.h>
#include <kernel/panic.h>
#include <kernel/kmalloc.h>
#include <stddef.h>
#include <stdint.h>

static uintptr_t heap_start;
static uintptr_t heap_end;
static uintptr_t heap_ptr;
static uint8_t heap_initialized = 0;

void heap_init(uintptr_t _heap_start, uintptr_t _heap_end) {
    heap_start = heap_ptr = _heap_start;
    heap_end = _heap_end;
    heap_initialized = 1;
    
    kdprintf("heap initialized between %x and %x\ntotal heap size: %d bytes\n", heap_start, heap_end, heap_end - heap_start);
}

void *kmalloc(size_t n) {
    void *ptr = (void *) heap_ptr;
    
    if (!heap_initialized) {
        panic("used kmalloc before heap initialization");
    }
    if (heap_ptr + n > heap_end) {
        panic("out of memory");
    }
    
    heap_ptr += n;
    return ptr;
}