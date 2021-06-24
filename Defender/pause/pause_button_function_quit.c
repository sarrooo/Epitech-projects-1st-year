/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** resume game pause menu
*/

#include "include/defender.h"

void quit_game_pause(game_t *main_s)
{
    animation_rect_clic(main_s, *main_s->menu_pause->quit);
    sfRenderWindow_close(main_s->win);
}