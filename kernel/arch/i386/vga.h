#ifndef _KERNEL_ARCH_I386_VGA_H
#define _KERNEL_ARCH_I386_VGA_H

#include <stdint.h>
#include <sys/io.h>

enum vga_color {
    VGA_COLOR_BLACK             = 0b0000,
    VGA_COLOR_BLUE              = 0b0001,
    VGA_COLOR_GREEN             = 0b0010,
    VGA_COLOR_CYAN              = 0b0011,
    VGA_COLOR_RED               = 0b0100,
    VGA_COLOR_MAGENTA           = 0b0101,
    VGA_COLOR_BROWN             = 0b0110,
    VGA_COLOR_WHITE             = 0b0111,
    VGA_COLOR_BLACK_INTENSE     = 0b1000,
    VGA_COLOR_BLUE_INTENSE      = 0b1001,
    VGA_COLOR_GREEN_INTENSE     = 0b1010,
    VGA_COLOR_CYAN_INTENSE      = 0b1011,
    VGA_COLOR_RED_INTENSE       = 0b1100,
    VGA_COLOR_MAGENTA_INTENSE   = 0b1101,
    VGA_COLOR_BROWN_INTENSE     = 0b1110,
    VGA_COLOR_WHITE_INTENSE     = 0b1111,
};

static inline uint8_t vga_color_create(enum vga_color fg_color, enum vga_color bg_color) {
    return fg_color | bg_color << 4;
}

static inline uint16_t vga_entry_create(uint8_t charcode, uint8_t attribute) {
    return ((uint16_t)attribute << 8) | charcode;
}

static inline void vga_putchar(uint32_t col, uint32_t ln, uint16_t entry) {
    uint16_t *ptr = (uint16_t *)(0xB8000 + ln * 160 + col * 2);
    *ptr = entry;
}

static void vga_move_cursor(uint32_t x, uint32_t y) {
    uint32_t pos = y * 80 + x;
    outb(0x0e, 0x3d4);
    outb((uint8_t)((pos >> 8) & 0xff), 0x3d5);
    outb(0x0f, 0x3d4);
    outb((uint8_t)(pos & 0xff), 0x3d5);
}

#endif
