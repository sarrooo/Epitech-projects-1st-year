/*
** EPITECH PROJECT, 2020
** Detect parameters of function
** File description:
** Detect indicateur, width, ...
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>

int det_ty(char type);

int det_ind(char type)
{
    if (type == '-')
        return (1);
    if (type == '+')
        return (2);
    if (type == '0')
        return (3);
    if (type == ' ')
        return (4);
    if (type == '#')
        return (5);
    return (0);
}

int det_prec(char *str, int i)
{
    char *res = malloc(sizeof(char) * my_strlen(str));
    int b = 0;

    if (str[i] != '.')
        return (-1);
    i = i + 1;
    for (i; det_ty(str[i]) == 0 && str[i] != 0; i++)
        res[b++] = str[i];
    res[b] = 0;
    if (str[i] == 0)
        return (-1);
    return (my_getnbr(res));
}

int det_wid(char *str, int i)
{
    char *res = malloc(sizeof(char) * my_strlen(str));
    int b = 0;

    if (str[i] == '.')
        return (-1);
    if (det_ty(str[i]) != 0)
        return (-1);
    while (str[i] != '.' && det_ty(str[i]) == 0 && str[i] != 0) {
        if (str[i] < 48 && str[i] > 57)
            return (-1);
        res[b++] = str[i++];
    }
    res[b] = 0;
    if (str[i] == 0)
        return (-1);
    return (my_getnbr(res));
}
