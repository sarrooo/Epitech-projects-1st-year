/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** check list at start
*/

#include "lib/my.h"
#include "include/my.h"

int check_start(list *l_a, list *l_b)
{
    if (l_a->first == NULL) {
        my_printf("Wrong entry\n");
        return 84;
    }
    if (check_sort(l_a, l_b) == 1) {
        my_printf("\n");
        return 0;
    }
    return 1;
}