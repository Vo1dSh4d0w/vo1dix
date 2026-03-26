#include <kernel/init.h>
#include <kernel/kmalloc.h>
#include <kernel/panic.h>
#include "multiboot.h"
#include <stdint.h>
#include <stdio.h>

extern uint8_t __kernel_image_end;

void arch_early_init(void *boot_info) {
    struct multiboot_boot_info *mbi = (struct multiboot_boot_info *)boot_info;
    struct multiboot_mmap_entry *mmap;
    uintptr_t largest_memory_area_end = 0;
    uint32_t largest_memory_area_length = 0;
    
    if (!(mbi->flags & MULTIBOOT_BI_FLAG_MMAP)) {
        panic("Bootloader did not provide memory map information.");
    }
    
    printf("mmap_length: %d\nmmap_addr: %x\n", mbi->mmap_length, mbi->mmap_addr);
    for (
        mmap = (struct multiboot_mmap_entry *) mbi->mmap_addr;
        (uintptr_t) mmap < (uintptr_t)mbi->mmap_addr + mbi->mmap_length;
        mmap = (struct multiboot_mmap_entry *) ((uintptr_t) mmap + mmap->size + sizeof(mmap->size))
    ) {
        printf("mmap entry: base_addr = %x, length = %x, type = %d\n", mmap->base_addr, mmap->length, mmap->type);
        if (mmap->type == 1 && (largest_memory_area_end == 0 || largest_memory_area_length < mmap->length)) {
            largest_memory_area_end = (uintptr_t) (mmap->base_addr + mmap->length);
            largest_memory_area_length = mmap->length;
        }
    }
    
    printf("__kernel_image_end = %x\n", (uint64_t)&__kernel_image_end);
    heap_init((uintptr_t)&__kernel_image_end, largest_memory_area_end);
}
