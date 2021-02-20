/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** set list
*/

#include "include/my.h"

void insert_obs(obs *obj, list_obs *obs_list, int x, int y)
{
    obs *number_1 = obs_list->first;

    obj->next = NULL;
    obj->x = x;
    obj->y = y;
    if (obs_list->first == NULL) {
        number_1 = obj;
        obs_list->first = number_1;
    }
    else {
        while (number_1->next != NULL)
            number_1 = number_1->next;
        number_1->next = obj;
    }
}

void struct_obs_2(list *l_a, int i)
{
    int nb = l_a->map->nb_cols;

    for (int j = 0; l_a->map->map_array[i][j] != 0 && j <= nb; j++) {
        if (l_a->map->map_array[i][j] == '1')
            insert_obs(create_cat(l_a), l_a->list_enemy, i, j);
        if (l_a->map->map_array[i][j] == '2')
            insert_obs(create_dodo(l_a), l_a->list_enemy, i, j);
        if (l_a->map->map_array[i][j] == '3')
            insert_obs(create_bird(l_a), l_a->list_enemy, i, j);
        if (l_a->map->map_array[i][j] == '4')
            insert_obs(create_bonus(l_a), l_a->list_enemy, i, j);
        if (l_a->map->map_array[i][j] == '5')
            insert_obs(create_malus(l_a), l_a->list_enemy, i, j);
        if (l_a->map->map_array[i][j] == 'E')
            insert_end_line(l_a, i, j);
    }
}

void struct_obs(list *l_a)
{
    int i = l_a->map->nb_lines - 1;
    l_a->list_enemy->first = NULL;

    for (i; i >= 0; i--) {
        struct_obs_2(l_a, i);
    }
}

void set_pos_obs(list *l_a)
{
    obs *element = l_a->list_enemy->first;
    int *siz;
    sfVector2f ps = {0, 0};

    while (element != NULL) {
        ps.x = 600 + (element->y * 50);
        if (element->type == 1) {
            siz = size_element(element, 3, 3);
            ps.y = 444 - (siz[1] + 5) * (l_a->map->nb_lines - 1 - element->x);
        }
        if (element->type == 2) {
            siz = size_element(element, 4, 2);
            ps.y = 420 - (siz[1] + 30) * (l_a->map->nb_lines - 1 - element->x);
        }
        sfSprite_setPosition(element->sprite, ps);
        set_pos_bonus(l_a, element, ps);
        element = element->next;
    }
}

void move_obs(list *l_a)
{
    obs *element = l_a->list_enemy->first;

    while (element != NULL) {
        if (element->type == 1)
            move_cat(element, l_a->win);
        if (element->type == 2)
            move_dodo(element, l_a->win);
        if (element->type == 3)
            move_bird(element, l_a->win);
        sfSprite_move(element->sprite, element->move);
        element = element->next;
    }
    sfSprite_move(l_a->list_enemy->end->sprite, l_a->list_enemy->end->move);
}