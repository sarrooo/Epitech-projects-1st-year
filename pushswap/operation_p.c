/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** operation p on list
*/

#include "lib/my.h"
#include "include/my.h"
#include <unistd.h>

void pa(list *l_a, list *l_b)
{
    list temp = *l_b;
    element *current = temp.first;
    list temp_2 = *l_a;
    element *current2 = temp_2.first;

    if (l_b->first != NULL) {
        l_a->first = l_b->first;
        l_b->first = current->next;
        if (current->next != NULL)
            current->next->prev = NULL;
        l_a->first->next = current2;
        if (l_a->first->next == NULL) {
            l_a->last = l_a->first;
            l_a->first->prev = NULL;
        }
        else
            l_a->first->next->prev = l_a->first;
    }
}

void pb(list *l_a, list *l_b)
{
    list temp = *l_a;
    element *current = temp.first;
    list temp_2 = *l_b;
    element *current2 = temp_2.first;

    if (l_a->first != NULL) {
        l_b->first = l_a->first;
        l_a->first = current->next;
        if (current->next != NULL)
            current->next->prev = NULL;
        l_b->first->next = current2;
        if (l_b->first->next == NULL) {
            l_b->last = l_b->first;
            l_b->first->prev = NULL;
        }
        else
            l_b->first->next->prev = l_b->first;
    }
}