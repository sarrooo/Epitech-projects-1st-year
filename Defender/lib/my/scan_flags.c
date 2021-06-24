/*
** EPITECH PROJECT, 2020
** printf
** File description:
** scan sign
*/

int my_getnbr(char const *str);
#include <stdlib.h>

int *scan_flags_width(char *format, int i, int k, int *flags)
{
    char *str;
    int x = k;

    flags[5] = k - i;
    for (; format[x] >= '0' && format[x] <= '9'; x++);
    str = malloc(sizeof(char) * x + 1);
    for (x = 0; format[x + k] >= '0' && format[x + k] <= '9'; x++) {
        str[x] = format[x + k];
    }
    str[x] = '\0';
    flags[5] += x;
    flags[6] = my_getnbr(str);
    return (flags);
}

int *scan_flags(char *format, int i, int *flags)
{
    int k = 0;

    for (k = i; format[k] == '-' || format[k] == '+' ||
    format[k] == '0' || format[k] == ' ' || format[k] == '#'; k++) {
        if (format[k] == '+') {
            flags[0] = 1;
            flags[3] = 0;
        }
        if (format[k] == '-')
            flags[1] = 1;
        if (format[k] == '0')
            flags[2] = 1;
        if (format[k] == ' ' && flags[0] != 1)
            flags[3] = 1;
        if (format[k] == '#')
            flags[4] = 1;
    }
    scan_flags_width(format, i, k, flags);
    return (flags);
}