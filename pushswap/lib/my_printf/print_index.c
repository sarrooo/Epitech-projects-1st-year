/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** Print indicateur, width, ...
*/

#include "my.h"

int prt_ind(int arg, int *spe)
{
    if (spe[1] == 2 && arg > 0 && spe[0] != 2)
        my_putchar('+');
    else if (spe[1] == 4 && arg > 0)
        my_putchar(' ');
}

int prt_ind_uns(int type, int *spe)
{
    if (spe[1] == 5) {
        if (type == 5)
            my_putchar('0');
        if (type == 6)
            my_putstr("0x");
        if (type == 7)
            my_putstr("0X");
    }
}
