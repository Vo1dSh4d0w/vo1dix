#include "arch/i386/vga.h"

void kernel_main() {
    vga_putchar(0, 0, vga_entry_create('H', VGA_COLOR_WHITE));
    vga_putchar(1, 0, vga_entry_create('e', VGA_COLOR_WHITE));
    vga_putchar(2, 0, vga_entry_create('l', VGA_COLOR_WHITE));
    vga_putchar(3, 0, vga_entry_create('l', VGA_COLOR_WHITE));
    vga_putchar(4, 0, vga_entry_create('o', VGA_COLOR_WHITE));
    vga_putchar(5, 0, vga_entry_create(',', VGA_COLOR_WHITE));
    vga_putchar(6, 0, vga_entry_create(' ', VGA_COLOR_WHITE));
    vga_putchar(7, 0, vga_entry_create('w', VGA_COLOR_WHITE));
    vga_putchar(8, 0, vga_entry_create('o', VGA_COLOR_WHITE));
    vga_putchar(9, 0, vga_entry_create('r', VGA_COLOR_WHITE));
    vga_putchar(10, 0, vga_entry_create('l', VGA_COLOR_WHITE));
    vga_putchar(11, 0, vga_entry_create('d', VGA_COLOR_WHITE));
    vga_putchar(12, 0, vga_entry_create('!', VGA_COLOR_WHITE));
    for (;;) {}
}