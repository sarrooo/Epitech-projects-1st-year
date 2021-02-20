/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** sort list
*/

#include "lib/my.h"
#include "include/my.h"
#include <unistd.h>

int check_sort(list *l_a, list *l_b)
{
    element *current = l_a->first;
    element *second = current->next;
    element *current_b = l_b->first;

    if (current_b != NULL)
        return 0;
    for (int i = 0; current->next != NULL; i++) {
        if (current->nb > second->nb)
            return 0;
        current = current->next;
        second = second->next;
    }
    return 1;
}

int comp_buff(char *str, int *j)
{
    int i = 0;
    int x = 0;

    for (i = 0; x < j[1]; i += 4) {
        str[i] = 'r';
        str[i + 1] = 'r';
        str[i + 2] = 'a';
        str[i + 3] = ' ';
        x++;
    }
    return (i);
}

void print_operation(int *j)
{
    char *str;
    int i = 0;

    if (j[0] != 0) {
        str = malloc(sizeof(char) * ((j[0] * 3) + 4));
        i = comp_buff_2(str, j);
    }
    else {
        str = malloc(sizeof(char) * ((j[1] * 4) + 4));
        i = comp_buff(str, j);
    }
    str[i] = 'p';
    str[i + 1] = 'b';
    str[i + 2] = ' ';
    str[i + 3] = 0;
    write(1, str, my_strlen(str));
    free(str);
}

element home_sort_2(list *l_a, list *l_b, element max_temp, int size)
{
    element *current = l_a->first;
    int max_i = 0;
    int j[] = {0, 0};

    for (int i = 0; current != NULL; i++) {
        if (max_temp.nb < current->nb) {
            max_temp = *current;
            max_i = i;
        }
        current = current->next;
    }
    if (max_i <= size / 2)
        for (j[0]; max_temp.nb != l_a->first->nb; j[0]++)
            ra(l_a);
    if (max_i > size / 2)
        for (j[1]; max_temp.nb != l_a->first->nb; j[1]++)
            rra(l_a);
    last_func(j, l_a, l_b);
    if (l_a->first != NULL)
        max_temp = *l_a->first;
    return (max_temp);
}

void home_sort(list *l_a, list *l_b)
{
    element *current = l_a->first;
    element max_temp = *l_a->first;
    int size = list_len(l_a);
    int size_temp = size - 1;
    int max_i = 0;

    while (size > 1) {
        max_temp = home_sort_2(l_a, l_b, max_temp, size);
        size--;
    }
    while (size_temp > 0) {
        write(1, "rrb pa ", 7);
        size_temp--;
    }
    write(1, "rra", 3);
}