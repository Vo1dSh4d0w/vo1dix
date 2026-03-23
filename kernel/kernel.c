#include <stddef.h>
#include <stdio.h>
#include <string.h>

void kernel_main() {
    char my_str[1024] = "Hello, world!\nBarriage Return\rC\n";
    
    memset(my_str + strlen(my_str), 'A', 160);
    
    for (size_t idx = 0; my_str[idx]; idx++) {
        putchar(my_str[idx]);
    }
    
    for (;;) {}
}