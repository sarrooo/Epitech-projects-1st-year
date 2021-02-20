/*
** EPITECH PROJECT, 2020
** int_to_str
** File description:
** int to str
*/

#include "my.h"
#include <stdlib.h>

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
    char *str = malloc(sizeof(char) * 10);

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

char *str_cat(char *s1, char *s2)
{
    char *dest = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
    int i = 0;

    for (i = 0; i < my_strlen(s1); i++)
        dest[i] = s1[i];
    for (int z = 0; z < my_strlen(s2); z++)
        dest[i++] = s2[z];
    dest[i] = 0;
    return (dest);
}