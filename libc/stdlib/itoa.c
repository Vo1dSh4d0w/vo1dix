#include <stdlib.h>

#define ITOA_FN(FNAME, TYPE) void FNAME(char *buf, TYPE i, int base) {\
    unsigned TYPE ui = i, rem;\
    char *ptr = buf, *left, *right, tmp;\
\
    if (i < 0) {\
        *ptr++ = '-';\
        buf++;\
        ui = -i;\
    }\
\
    do {\
        rem = ui % base;\
        *ptr++ = rem < 10 ? '0' + rem : 'a' + rem - 10;\
    } while (ui /= base);\
\
    *ptr = 0;\
    left = buf;\
    right = ptr - 1;\
\
    while (left < right) {\
        tmp = *left;\
        *left = *right;\
        *right = tmp;\
\
        left++;\
        right--;\
    }\
}


#define UTOA_FN(FNAME, TYPE) void FNAME(char *buf, unsigned TYPE i, int base) {\
    unsigned TYPE rem;\
    char *ptr = buf, *left, *right, tmp;\
\
    do {\
        rem = i % base;\
        *ptr++ = rem < 10 ? '0' + rem : 'a' + rem - 10;\
    } while (i /= base);\
\
    *ptr = 0;\
    left = buf;\
    right = ptr - 1;\
\
    while (left < right) {\
        tmp = *left;\
        *left = *right;\
        *right = tmp;\
\
        left++;\
        right--;\
    }\
}

ITOA_FN(itoa, int)
ITOA_FN(ltoa, long)
ITOA_FN(lltoa, long long)

UTOA_FN(utoa, int)
UTOA_FN(ultoa, long)
UTOA_FN(ulltoa, long long)