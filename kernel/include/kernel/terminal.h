#ifndef _KERNEL_TERMINAL_H
#define _KERNEL_TERMINAL_H

#include <stdint.h>

#define TERMINAL_ROWS 25
#define TERMINAL_COLS 80

struct terminal_cell {
    uint8_t ch;
    uint8_t attr;
};

enum terminal_type {
    TTYPE_VGA  
};

typedef struct {
    struct terminal_cell cells[TERMINAL_ROWS][TERMINAL_COLS]; // make this dynamic in the future, when dynamic memory allocation is implemented
    
    enum terminal_type ttype;
    
    uint16_t col;
    uint16_t row;
    
    uint8_t attr;
} TERMINAL;

extern TERMINAL tty0; // at least one terminal should always exist

void terminal_set_attr(TERMINAL *term, uint8_t attr);
void terminal_putchar(TERMINAL *term, int c);

#endif