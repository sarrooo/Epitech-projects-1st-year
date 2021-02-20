/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** buffer of ra
*/

#include "lib/my.h"
#include "include/my.h"
#include <unistd.h>

int comp_buff_2(char *str, int *j)
{
    int i = 0;
    int x = 0;

    for (i = 0; x < j[0]; i += 3) {
        str[i] = 'r';
        str[i + 1] = 'a';
        str[i + 2] = ' ';
        x++;
    }
    return (i);
}