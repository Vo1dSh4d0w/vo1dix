#include <kernel/panic.h>
#include <stdio.h>

void panic(char *message) {
    printf("kernel panic: %s", message);
    asm volatile (
        "cli\n\t"
        "hlt\n\t"
    );
    
    for (;;);
}