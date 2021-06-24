/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** Printf part 2
*/

#include "my.h"
#include <stdarg.h>
#include <stddef.h>

int prt_ind(int arg, int *spe);

int prt_ind_uns(int type, int *spe);

int prt(int i, int arg, int *spe);

int prt_uns(int i, unsigned int arg, int *spe);

int pert_larg_int(int i, int arg, int *op);

int lrg_uns(int i, unsigned int arg, int *op);

int my_put_pre(int arg, int base, int *op);

int my_put_pre_uns(unsigned arg, int base, char *str, int *op);

int prt(int i, int arg, int *spe)
{
    prt_ind(arg, spe);
    if (i == 2) {
        if (arg <= 7) {
            my_putstr("\\00");
            my_put_nbr(arg, 8);
        }
        if (arg < 32 && arg > 7) {
            my_putstr("\\0");
            my_put_nbr(arg, 8);
        }
        if (arg > 127) {
            my_putstr("\\");
            my_put_nbr(arg, 8);
        }
        if (arg >= 32 && arg <= 127)
            my_putchar(arg);
    }
    if (i == 3)
        my_put_pre(arg, 10, spe);
    return (0);
}

int prt_str(char *str, int prec)
{
    if (str == NULL) {
        my_putstr("(null)");
        return (0);
    }
    for (int i = 0; i < prec; i++) {
        if (str[i] <= 7) {
            my_putstr("\\00");
            my_put_nbr(str[i], 8);
        }
        if (str[i] < 32 && str[i] > 7) {
            my_putstr("\\0");
            my_put_nbr(str[i], 8);
        }
        if (str[i] > 127) {
            my_putstr("\\");
            my_put_nbr(str[i], 8);
        }
        if (str[i] >= 32 && str[i] <= 127)
            my_putchar(str[i]);
    }
    return (0);
}

int prt_uns(int i, unsigned int arg, int *spe)
{
    prt_ind_uns(i, spe);
    if (i == 4)
        my_put_pre_uns(arg, 10, "0123456789", spe);
    if (i == 5)
        my_put_pre_uns(arg, 8, "01234567", spe);
    if (i == 6)
        my_put_pre_uns(arg, 16, "0123456789abcdef", spe);
    if (i == 7)
        my_put_pre_uns(arg, 16, "0123456789ABCDEF", spe);
    if (i == 8)
        my_put_pre_uns(arg, 2, "01", spe);
    if (i == 9) {
        my_putstr("0x");
        my_put_pre_uns(arg, 16, "0123456789abcdef", spe);
    }
    return (0);
}

int det_uns(char type)
{
    if (type == 'u')
        return (4);
    if (type == 'o')
        return (5);
    if (type == 'x')
        return (6);
    if (type == 'X')
        return (7);
    if (type == 'b')
        return (8);
    if (type == 'p')
        return (9);
    return (0);
}
