/*
** EPITECH PROJECT, 2020
** Print large
** File description:
** Print large paramameters
*/

#include "my.h"
#include <stdlib.h>

int prt_str(char *arg, int prec);

int prt(int i, int arg, int *spe);

int prt_uns(int i, unsigned int arg, int *spe);

int my_put_pre(int arg, int base, int *op);

int my_put_pre_uns(unsigned arg, int base, char *str, int *op);

int prt_larg(int *op, char *arg)
{
    int i = my_strlen(arg);

    if (op[3] >= 0)
        i = op[3];
    else
        op[3] = my_strlen(arg);
    if (op[1] == 1)
        prt_str(arg, op[3]);
    for (i; i < op[2]; i++)
        my_putchar(' ');
    if (op[1] != 1)
        prt_str(arg, op[3]);
    return (0);
}

int prt_space(int len, int *op)
{
    for (len; len < op[2]; len++)
        my_putchar(' ');
    return (0);
}

int pert_larg_int(int i, int arg, int *op)
{
    int len = 1;

    for (int b = 10; arg >= b && b <= 1000000000; b = b * 10)
        len++;
    if (op[1] == 2)
        len = len + 1;
    if (op[0] == 2)
        len = 1;
    len = (op[3] < len) ? len : len + (op[3] - len);
    if (op[1] == 3 && op[1] != 1) {
        for (len; len < op[2]; len++)
            my_putchar('0');
        prt(i, arg, op);
        return (0);
    }
    if (op[1] != 1)
        prt_space(len, op);
    prt(i, arg, op);
    if (op[1] == 1)
        prt_space(len, op);
    return (0);
}

int lrg_uns(int i, unsigned int arg, int *op)
{
    int len = 1;

    for (unsigned int b = 10; arg >= b && b <= 1000000000; b = b * 10)
        len++;
    len = (op[3] < len) ? len : len + (op[3] - len);
    if (op[1] == 3 && op[1] != 1) {
        for (len; len < op[2]; len++)
            my_putchar('0');
        prt_uns(i, arg, op);
        return (0);
    }
    if (op[1] != 1)
        prt_space(len, op);
    prt_uns(i, arg, op);
    if (op[1] == 1)
        prt_space(len, op);
    return (0);
}

int *calcul_len(int *op)
{
    int *res = malloc(sizeof(int) * 2);
    int len_int = 0;
    int len_uns = 0;
    unsigned int v = 0;

    if (op[2] >= 0) {
        len_int = 1;
        for (int b = 10; b <= op[2] && b <= 1000000000; b = b * 10)
            len_int++;
    }
    res[0] = len_int;
    if (op[3] >= 0) {
        len_uns = 2;
        for (v = 10; op[3] >= v && v <= 1000000000; v = v * 10)
            len_uns++;
    }
    res[1] = len_uns;
    return (res);
}
