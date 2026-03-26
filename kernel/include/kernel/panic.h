#ifndef _KERNEL_PANIC_H
#define _KERNEL_PANIC_H


void panic(char *message) __attribute__ ((noreturn));

#endif