/*
** EPITECH PROJECT, 2020
** bs.h
** File description:
** prototype of my_function
*/

#ifndef MY_H_

#include <stdlib.h>

typedef struct element element;
struct element
{
    int nb;
    element *next;
    element *prev;
};

typedef struct list
{
    element *first;
    element *last;
}list;

char *str_cat(char *s1, char *s2);

void insert_nb(int num, list *nb_list);

list *start_list(int ac, char **av);

void list_filling(int ac, char **av, list *nb_list);

void print_list(list *nb_list);

int remove_first_element(list *nb_list);

void sa(list *l_a);

void sb(list *l_b);

void sc(list *l_a, list *l_b);

int list_len(list *nb_list);

void pa(list *l_a, list *l_b);

void pb(list *l_a, list *l_b);

void ra(list *l_a);

void rb(list *l_b);

void rr(list *l_a, list *l_b);

void rra(list *l_a);

void rra_last(list *l_a);

void rrb(list *l_b);

void rrr(list *l_a, list *l_b);

int check_sort(list *l_a, list *l_b);

int bubble_sort(list *l_a, list *l_b);

int bubble_sort_2(list **la, element **element_a, int i);

int max_list(list *l_a);

int check_start(list *l_a, list *l_b);

void home_sort(list *l_a, list *l_b);

void last_func(int *j, list *l_a, list *l_b);

void print_operation(int *j);

int comp_buff_2(char *str, int *j);

#endif
