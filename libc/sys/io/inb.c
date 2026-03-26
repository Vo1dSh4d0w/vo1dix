#include <sys/io.h>

unsigned char inb(unsigned short port) {
    unsigned char ret;
    asm volatile (
        "inb %w1, %b0"
        : "=a"(ret)
        : "Nd"(port)
        : "memory"
    );
    return ret;
}