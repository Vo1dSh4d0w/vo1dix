#include <ctype.h>
#include <kernel/terminal.h>
#include <stdint.h>
#include <string.h>
#include "vga.h"

TERMINAL tty0 = {
    .cells = {},

    .col = 0,
    .row = 0,

    .attr = VGA_COLOR_WHITE,
    .ttype = TTYPE_VGA,
};

static void terminal_render_cell(TERMINAL* term, uint16_t row, uint16_t col) {
    switch (term->ttype) {
        case TTYPE_VGA:
        vga_putchar(col, row, vga_entry_create((uint8_t) term->cells[row][col].ch, term->cells[row][col].attr));
        break;
    }
}

static void terminal_scroll(TERMINAL *term) {
    memmove(term->cells[0], term->cells[1], sizeof(term->cells[0]) * (TERMINAL_ROWS - 1));
    memset(term->cells[TERMINAL_ROWS - 1], 0, sizeof(term->cells[TERMINAL_ROWS - 1]));
    term->row = TERMINAL_ROWS - 1;
}

static void terminal_render_full(TERMINAL *term) {
    int r, c;
    for (r = 0; r < TERMINAL_ROWS; r++) {
        for (c = 0; c < TERMINAL_COLS; c++) {
            terminal_render_cell(term, r, c);
        }
    }
}

void terminal_set_attr(TERMINAL *term, uint8_t attr) {
    term->attr = attr;
}

void terminal_putchar(TERMINAL *term, int c) {
    if (c == '\n') {
        term->col = 0;
        term->row++;
    } else if (c == '\r') {
        term->col = 0;
    } else if (isprint(c)) {
        term->cells[term->row][term->col].ch = c;
        term->cells[term->row][term->col].attr = term->attr;
        terminal_render_cell(term, term->row, term->col);

        term->col++;
        if (term->col >= TERMINAL_COLS) {
            term->col = 0;
            term->row++;
        }
    }
    if (term->row >= TERMINAL_ROWS) {
        terminal_scroll(term);
        terminal_render_full(term);
    }
}
