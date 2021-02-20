/*
** EPITECH PROJECT, 2020
** int_to_str
** File description:
** cast int to str
*/

#include <stdlib.h>
#include "lib/my.h"

char int_str(int nb, int base)
{
    if (nb < base && nb >= 0) {
        return (nb + 48);
    }
    if (base <= nb) {
        int_str(nb / base, base);
        int_str(nb % base, base);
    }
}

char *str_int(int nb)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 1000);

    if (nb < 0)
        nb = nb * -1;
    while (nb >= 10) {
        str[i++] = int_str(nb % 10, 10);
        nb = nb / 10;
    }
    str[i++] = int_str(nb, 10);
    str[i] = 0;
    return (my_revstr(str));
}
