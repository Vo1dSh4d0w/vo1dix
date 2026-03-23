#include <stddef.h>
#include <stdio.h>

void kernel_main() {
    for (int i = 0; i < 29; i++) {
        printf("Hello, world! %d\n", i);
    }
    
    for (;;) {}
}