#ifndef MY_UTILS_H
#define MY_UTILS_H

#include <stdio.h>

/**
 * keep in mind that the return value of a function
 * is very important, as the value of the variable counld
 * change during the called function
 */

/* convert int32_t to char array end with '\0' and returns str */
char *itostr(int a, char *str);
/* concatenate src to back of dest and returns dest */
char *strconcat(char *dest, char *src);
/* convert src to a string inside heap */
char *init_str_from_stack(unsigned int size, char *src);

#endif