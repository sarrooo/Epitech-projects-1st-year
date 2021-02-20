/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** sort list
*/

#include "lib/my.h"
#include "include/my.h"
#include <unistd.h>

void insert_nb_start(int num, list *nb_list)
{
    element *number = malloc(sizeof(element));

    number->nb = num;
    number->prev = NULL;
    number->next = nb_list->first;
    number->next->prev = number;
    nb_list->first = number;
}

void insert_nb_last(int num, list *nb_list)
{
    element *number = malloc(sizeof(element));

    number->nb = num;
    number->next = nb_list->first;
    number->prev = NULL;
    nb_list->first = number;
    nb_list->last = number;
}

int list_fill_start(int ac, char **av, list *l_a)
{
    int size;

    if (ac < 1)
        return 84;
    insert_nb_last(my_getnbr(av[ac - 1]), l_a);
    for (int i = ac - 2; i > 0; i--) {
        insert_nb_start(my_getnbr(av[i]), l_a);
    }
    return 0;
}

int main(int ac, char **av)
{
    list *l_a = start_list(ac, av);
    list *l_b = start_list(ac, av);
    int error;

    list_fill_start(ac, av, l_a);
    error = check_start(l_a, l_b);
    if (error != 1)
        return (error);
    home_sort(l_a, l_b);
    write(1, "\n", 1);
    return 0;
}