/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** operation rr for pushswap
*/

#include "lib/my.h"
#include "include/my.h"
#include <unistd.h>

void rra(list *l_a)
{
    element *first = l_a->first;
    element *last = l_a->first;
    element *current = l_a->first;

    if (l_a != NULL && current->next != NULL) {
        last = l_a->last->prev;
        last->next = NULL;
        l_a->last->next = first;
        l_a->last->prev = NULL;
        first->prev = l_a->last;
        l_a->first = l_a->last;
        l_a->last = last;
    }
}

void rrb(list *l_b)
{
    element *first = l_b->first;
    element *last = l_b->first;
    element *current = l_b->first;

    if (l_b->first != NULL && current->next != NULL) {
        last = l_b->last->prev;
        last->next = NULL;
        l_b->last->next = first;
        l_b->last->prev = NULL;
        first->prev = l_b->last;
        l_b->first = l_b->last;
        l_b->last = last;
    }
}

void rra_last(list *l_a)
{
    element *first = l_a->first;
    element *last = l_a->first;
    element *current = l_a->first;

    if (l_a != NULL && current->next != NULL) {
        last = l_a->last->prev;
        last->next = NULL;
        l_a->last->next = first;
        l_a->last->prev = NULL;
        first->prev = l_a->last;
        l_a->first = l_a->last;
        l_a->last = last;
        write(1, "rra", 3);
    }
}

void rrr(list *l_a, list *l_b)
{
    rra(l_a);
    rrb(l_b);
}
