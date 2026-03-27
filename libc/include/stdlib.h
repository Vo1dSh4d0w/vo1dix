#ifndef _LIBC_STDLIB_H
#define _LIBC_STDLIB_H

void itoa(char *buf, int n, int base);
void ltoa(char *buf, long n, int base);
void lltoa(char *buf, long long n, int base);

void utoa(char *buf, unsigned int n, int base);
void ultoa(char *buf, unsigned long n, int base);
void ulltoa(char *buf, unsigned long long n, int base);

#endif