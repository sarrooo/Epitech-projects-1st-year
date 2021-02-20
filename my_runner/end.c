/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** end of game
*/

#include "include/my.h"

void destroy_all(list *l_a)
{
    sfMusic_destroy(l_a->music);
    sfMusic_destroy(l_a->jump_fx);
    sfRenderWindow_destroy(l_a->win);
    free(l_a->list_enemy);
    free(l_a->girl);
    free(l_a->map);
    free(l_a->par);
}