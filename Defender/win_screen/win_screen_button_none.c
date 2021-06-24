/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** set button to orignal status
*/

#include "include/defender.h"

void win_screen_check_button_none(game_t *main_s)
{
    animation_circle_none(main_s, main_s->win_screen->quit_button);
    animation_rect_none(main_s, main_s->win_screen->menu_button);
    animation_rect_none(main_s, main_s->win_screen->replay_button);
}