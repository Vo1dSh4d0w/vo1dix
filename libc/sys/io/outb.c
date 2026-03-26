#include <sys/io.h>

void outb(unsigned char value, unsigned short port) {
    asm volatile (
        "outb %b0, %w1"
        :
        : "a"(value), "Nd"(port)
        : "memory"
    );
}
