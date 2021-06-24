/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** Print precision param
*/

#include "my.h"

int my_put_pre(int arg, int base, int *op)
{
    int len = 1;

    for (int b = 10; arg >= b && b < 1000000000; b = b * 10)
        len++;
    if (op[1] == 2)
        len = len + 1;
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
