/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** Recode printf function
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>

int prt(int i, int arg, int *spe);

int prt_str(char *arg);

int prt_uns(int i, unsigned int arg, int *spe);

int det_uns(char type);

int det_ind(char type);

int det_prec(char *str, int i);

int det_wid(char *str, int i);

int pert_larg_int(int i, int arg, int *op);

int lrg_uns(int i, unsigned int arg, int *op);

int prt_larg(int *op, char *arg);

int *calcul_len(int *op);

int det_ty(char type)
{
    if (type == 's' || type == 'S')
        return (1);
    if (type == 'c' || type == 'C')
        return (2);
    if (type == 'd' || type == 'i')
        return (3);
    if (det_uns(type) != 0)
        return (det_uns(type));
    if (type == '%')
        return (0);
    return (0);
}

int *detect_error(char *str, int x, int *op)
{
    int len_int = 0;
    int len_uns = 0;
    int len_total = 0;
    int len_correct = 1;
    int *correct = malloc(sizeof(int) * 1);

    correct[0] = 0;
    if (op[2] > 0)
        len_int = calcul_len(op)[0];
    if (op[3] >= 0)
        len_uns = calcul_len(op)[1];
    if (op[1] != 0)
        len_correct = len_correct + 1;
    len_correct = len_correct + len_int + len_uns;
    for (x; str[x] != '%'; x--)
        len_total++;
    if (len_total != len_correct)
        return (correct);
    return (op);
}

int *det_per(char *str, int i)
{
    int *arr = malloc(sizeof(int) * 5);
    int x = 0;

    arr[0] = 0;
    if (str[i++] != '%')
        return (arr);
    for (x = i; det_ty(str[x]) == 0 && str[x] != 0; x++);
    if (x > my_strlen(str))
        return (arr);
    arr[0] = det_ty(str[x]);
    arr[1] = det_ind(str[i]);
    if (arr[1] != 0 && i + 1 <= my_strlen(str))
        i = i + 1;
    arr[2] = det_wid(str, i);
    if (arr[2] >= 0)
        for (i = i + 1; det_prec(str, i) < 0 && i <= my_strlen(str); i++);
    arr[3] = det_prec(str, i);
    if (arr[3] >= 0 && i + 1 <= my_strlen(str))
        i = i + 1;
    arr[4] = x;
    return (detect_error(str, x, arr));
}

int det_double_per(char *str, int i)
{
    if (str[i] == '%' && str[i + 1] == '%') {
        my_putchar('%');
        i = i + 2;
    }
    return (i);
}

int my_printf(char *s, ...)
{
    va_list ap;
    char *x;
    int i = 0;

    va_start(ap, s);
    for (int i = 0; i < my_strlen(s); i++) {
        i = det_double_per(s, i);
        if (det_per(s, i)[0] == 1)
            prt_larg(det_per(s, i), va_arg(ap, char *));
        if (det_per(s, i)[0] > 1 && det_per(s, i)[0] < 4)
            pert_larg_int(det_per(s, i)[0], va_arg(ap, int), det_per(s, i));
        if (det_per(s, i)[0] > 3 && det_per(s, i)[0] < 10)
            lrg_uns(det_per(s, i)[0], va_arg(ap, unsigned int), det_per(s, i));
        if (det_per(s, i)[0] == 0)
            my_putchar(s[i]);
        if (det_per(s, i)[0] > 0)
            i = det_per(s, i)[4];
    }
    va_end(ap);
    return (0);
}
