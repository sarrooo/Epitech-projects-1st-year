/*
** EPITECH PROJECT, 2020
** mem_alloc.c
** File description:
** Memory allocation
*/

#include <stdlib.h>

int my_strlen(char const *str);

int my_putstr(char const *str);

char *mem_alloc(char const *a, char const *b)
{
    char *dest = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b)));
    int i = 0;

    for (i = 0; i < my_strlen(a); i++)
        dest[i] = a[i];
    for (int x = 0; x < my_strlen(b); x++)
        dest[i++] = b[x];
    dest[i] = 0;
    return (dest);
}

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **dest = malloc(sizeof(char *) * (nb_rows + 1));

    for (int i = 0; i < nb_rows; i++) {
        dest[i] = malloc(sizeof(char) * (nb_cols + 1));
    }
    return (dest);
}

char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols)
{
    char **dest = mem_alloc_2d_array(nb_rows, nb_cols);

    dest = arr;
    return (dest);
}
