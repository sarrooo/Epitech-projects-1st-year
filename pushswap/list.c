/*
** EPITECH PROJECT, 2020
** push_swap
** File description:
** create, ... list
*/

#include "lib/my.h"
#include "include/my.h"

void insert_nb(int num, list *nb_list)
{
    element *number = malloc(sizeof(element));
    element *number_1 = nb_list->first;

    number->nb = num;
    number->next = NULL;
    if (nb_list->first == NULL) {
        number_1 = number;
        nb_list->first = number_1;
    }
    else {
        while (number_1->next != NULL)
            number_1 = number_1->next;
        number_1->next = number;
    }
}

list *start_list(int ac, char **av)
{
    list *nb_list = malloc(sizeof(list));
    element *number = malloc(sizeof(element));

    nb_list->first = NULL;
    nb_list->last = NULL;
    number->next = NULL;
    number->prev = NULL;
    return nb_list;
}

void list_filling(int ac, char **av, list *nb_list)
{
    for (int i = 1; i < ac; i++) {
        insert_nb(my_getnbr(av[i]), nb_list);
    }
}

void print_list(list *nb_list)
{
    element *current = nb_list->first;

    my_printf("\n");
    while (current != NULL) {
        my_printf("%d -> ", current->nb);
        current = current->next;
    }
    my_printf("NULL");
    my_printf("\n");
}

int remove_first_element(list *nb_list)
{
    element *remove = nb_list->first;

    if (nb_list->first == NULL || nb_list == NULL)
        return 84;
    nb_list->first = nb_list->first->next;
    free(remove);
    return 0;
}