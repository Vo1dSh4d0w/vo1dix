#include <kernel/init.h>
#include "mutliboot.h"
#include <stdio.h>

void arch_early_init(void *boot_info) {
    struct multiboot_boot_info *mbi = (struct multiboot_boot_info *)boot_info;
}
