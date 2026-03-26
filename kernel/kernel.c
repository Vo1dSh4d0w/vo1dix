#include <kernel/init.h>
#include <kernel/kmalloc.h>
#include <stddef.h>
#include <kernel/terminal.h>
#include <kernel/init.h>
#include <sys/io.h>
#include <stdio.h>

void kernel_main(void *boot_info) {
    arch_early_init(boot_info);

    uint8_t attr = 0;
    for (int i = 0; i < 24; i++) {
        if ((attr & 0b1111) == 0) {
            terminal_set_attr(&tty0, (attr++ & 0b1111) | 0b01110000);
        } else {
            terminal_set_attr(&tty0, attr++ & 0b1111);
        }
        printf("Hello, world! %x\n", (attr - 1) & 0b1111);
    }
    
    for (;;) {}
}
