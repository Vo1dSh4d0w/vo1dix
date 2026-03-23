#include <string.h>

size_t strlen(const char *s) {
    size_t l;
    for (l = 0; s[l]; l++);
    return l;
}