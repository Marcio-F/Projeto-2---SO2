#include "../include/util.h"

void memory_copy(char *source, char *dest, int nbytes) {
    int i;

    for (i = 0; i < nbytes; i++) {
        *(dest + i) = *(source + i);
    }
}

void memory_set(uint8 *dest, uint8 val, uint32 len) {
    uint8 *temp = (uint8 *)dest;

    for ( ; len != 0; len--) *temp++ = val;
}

void int_to_ascii(int n, char str[]) {
    int i, sign;

    if ((sign = n) < 0) n = -n;

    i = 0;

    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) str[i++] = '-';

    str[i] = '\0';
}

string int_to_string(int n) {
    string ch = malloc(50);
    int_to_ascii(n, ch);
    int len = strlength(ch);
    int i = 0,
    j = len - 1;

    while (i < (len/2 + len%2)) {
        char tmp = ch[i];
        ch[i] = ch[j];
        ch[j] = tmp;
        i++;
        j--;
    }

    return ch;
}

int str_to_int(string ch) {
    int n = 0;
    int p = 1;
    int strlen = strlength(ch);
    int i;

    for(i = strlen-1; i >= 0; i--) {
        n += ((int)(ch[i] - '0')) * p;
        p *= 10;
    }

    return n;
}

void *malloc(int nbytes) {
    static char *heap_ptr = 0;
    char *base;

    if (heap_ptr == 0) heap_ptr = (char *)0x10000;

    base = heap_ptr;
    heap_ptr += nbytes;

    return base;
}
