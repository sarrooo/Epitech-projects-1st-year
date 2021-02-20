/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** operation s on list
*/

#include "lib/my.h"
#include "include/my.h"
#include <unistd.h>

void sa(list *l_a)
{
    element *one = l_a->first;
    element *temp = one->next;

    if (list_len(l_a) > 2) {
        one->next = temp->next;
        temp->next = one;
        l_a->first = temp;
    }
}

void sb(list *l_b)
{
    element *one = l_b->first;
    element *temp = one->next;

    if (list_len(l_b) > 2) {
        one->next = temp->next;
        temp->next = one;
        l_b->first = temp;
    }
}

void sc(list *l_a, list *l_b)
{
    sa(l_a);
    sb(l_b);
}