/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** Print precision param
*/

#include "include/my.h"
#include <stdlib.h>

int *det_negative(int arg, int len, int *op)
{
    int *arr = malloc(sizeof(int) * 2);

    if (op[1] == 2)
        len = len + 1;
    if (op[0] == 2)
        len = 1;
    if (arg % 10 == 0)
        len = len + 1;
    if (arg < 0)
        arg = arg * -1;
    arr[0] = arg;
    arr[1] = len;
    return (arr);
}

int my_put_pre(int arg, int base, int *op)
{
    int len = 1;

    for (int b = 10; arg >= b && b < 1000000000; b = b * 10)
        len++;
    if (op[1] == 2)
        len = len + 1;
    if (arg % 10 == 0)
        len = len + 1;
    if (arg < 0) {
        len = len + 1;
        arg = arg * -1;
        my_putchar('-');
    }
    for (int i = 0; i < op[3] - len; i++)
        my_putchar('0');
    my_put_nbr(arg, 10);
}

int my_put_pre_uns(unsigned arg, int base, char *str, int *op)
{
    int len = 1;
    unsigned int b = 0;

    for (b = 10; arg >= b && b <= 1000000000; b = b * 10)
        len++;
    for (int i = 0; i < op[3] - len; i++)
        my_putchar('0');
    my_put_uns(arg, base, str);
}
