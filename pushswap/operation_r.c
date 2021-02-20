/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** operation r on list
*/

#include "lib/my.h"
#include "include/my.h"
#include <unistd.h>

void ra(list *l_a)
{
    element *first = l_a->first;
    element *last = l_a->first;
    element *current = l_a->first;

    if (l_a != NULL && current->next != NULL) {
        last = l_a->last;
        current->next->prev = NULL;
        l_a->first = current->next;
        first->next = NULL;
        first->prev = l_a->last;
        l_a->last = first;
        last->next = first;
        current = current->next;
    }
}

void rb(list *l_b)
{
    element *first = l_b->first;
    element *last = l_b->first;
    element *current = l_b->first;

    if (l_b != NULL && current->next != NULL) {
        last = l_b->last;
        current->next->prev = NULL;
        l_b->first = current->next;
        first->next = NULL;
        first->prev = l_b->last;
        l_b->last = first;
        last->next = first;
        current = current->next;
        write(1, "rb ", 3);
    }
}

void rr(list *l_a, list *l_b)
{
    ra(l_a);
    rb(l_b);
}