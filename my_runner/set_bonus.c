/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** set pos of bonus
*/

#include "include/my.h"

void set_pos_bonus(list *l_a, obs *element, sfVector2f ps)
{
    int *siz;

    if (element->type == 3) {
        siz = size_element(element, 3, 3);
        ps.y = 380 - (siz[1] - 60) * (l_a->map->nb_lines - 1 - element->x);
    }
    if (element->type == 4) {
        siz = size_element(element, 1, 1);
        ps.y = 430 - (siz[1] + 10) * (l_a->map->nb_lines - 1 - element->x);
    }
    if (element->type == 5) {
        siz = size_element(element, 1, 1);
        ps.y = 420 - (siz[1] + 10) * (l_a->map->nb_lines - 1 - element->x);
    }
    sfSprite_setPosition(element->sprite, ps);
}