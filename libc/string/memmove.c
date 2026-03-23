#include <string.h>

void *memmove(void *dest, const void *src, size_t n) {
    char *d = dest < src ? dest : dest + n;
    const char *s = dest < src ? src : src + n;
    if (dest < src) {
        while (n) {
            *d++ = *s++;
            n--;
        }
    } else {
        while (n) {
            *d-- = *s--;
            n--;
        }
    }
    return dest;
}