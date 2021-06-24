/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** set button to orignal status
*/

#include "include/defender.h"

void pause_check_button_none(game_t *main_s)
{
    animation_rect_none(main_s, main_s->menu_pause->quit);
    animation_rect_none(main_s, main_s->menu_pause->menu);
    animation_circle_none(main_s, main_s->menu_pause->music_minus);
    animation_circle_none(main_s, main_s->menu_pause->music_plus);
    animation_circle_none(main_s, main_s->menu_pause->rate_minus);
    animation_circle_none(main_s, main_s->menu_pause->rate_plus);
    animation_circle_none(main_s, main_s->menu_pause->resume);
}