#include <stddef.h>
#include <stdio.h>
#include <kernel/terminal.h>

void kernel_main() {
    uint8_t attr = 0;
    for (int i = 0; i < 24; i++) {
        if ((attr & 0b1111) == 0) {
            terminal_set_attr(&tty0, (attr++ & 0b1111) | 0b01110000);
        } else {
            terminal_set_attr(&tty0, attr++ & 0b1111);
        }
        printf("Hello, world! %x\n", i, (attr - 1) & 0b1111);
    }
    
    for (;;) {}
}