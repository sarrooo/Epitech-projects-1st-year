/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** operation on list
*/

#include "lib/my.h"
#include "include/my.h"

int list_len(list *nb_list)
{
    int size = 0;
    element *current = malloc(sizeof(element));

    current = nb_list->first;
    if (current == NULL)
        return size;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

int max_list(list *l_a)
{
    element *current = l_a->first;
    int max = 0;

    while (current) {
        if (current->nb > max)
            max = current->nb;
        current = current->next;
    }
    return max;
}

int print_last(list *nb_list)
{
    element *current = nb_list->last;

    my_printf("\n");
    while (current != NULL) {
        my_printf("%d <- ", current->nb);
        current = current->prev;
    }
    my_printf("NULL");
    my_printf("\n");
}
