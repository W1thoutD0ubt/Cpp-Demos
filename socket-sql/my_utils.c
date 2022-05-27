#include "my_utils.h"
#include <stdlib.h>

char *itostr(int a, char *str)
{
    unsigned int index = 0, ua = 0, tpow = 1;
    char c = 0;
    if ((a >> 31) & 1) {
        str[index++] = '-';
        a = ~a + 0x1;
        tpow = 3;
    }
    ua = a;
    while (ua /= 10) tpow++;
    do {
        c = a % 10;
        a = (a - c) / 10;
        str[tpow - (++index)] = c + '0';
    } while (a);
    str[++index] = '\0';
    return str;
}

char *strconcat(char *dest, char *src)
{
    int len1 = -1, len2 = -1, l = 0;
    while (dest[++len1]);
    while (src[++len2]);
    l = len1 + len2;
    dest = realloc(dest, l + 1);
    for (int i = len1;i < l;++i) {
        dest[i] = src[i - len1];
    }
    dest[l] = 0;
    return dest;
}

char *init_str_from_stack(unsigned int size, char *src)
{
    unsigned int pos = 0;
    char *target = (char *)malloc(size);
    while (src[pos]) {
        target[pos] = src[pos];
        pos++;
    }
    return target;
}