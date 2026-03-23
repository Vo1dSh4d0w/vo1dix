#include <stdio.h>
#ifdef __IS_LIBK
#include <kernel/terminal.h>
#endif

int putchar(int c) {
#ifdef __IS_LIBK
    terminal_putchar(&tty0, c);
#endif
    return c;
}
