/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** set button to orignal status
*/

#include "include/defender.h"

void setting_check_button_none(game_t *main_s)
{
    animation_rect_none(main_s, main_s->menu_setting->on_off_button);
    animation_rect_none(main_s, main_s->menu_setting->on_off_button_2);
    animation_circle_none(main_s, main_s->menu_setting->music_plus);
    animation_circle_none(main_s, main_s->menu_setting->music_minus);
    animation_circle_none(main_s, main_s->menu_setting->rate_plus);
    animation_circle_none(main_s, main_s->menu_setting->rate_minus);
    animation_circle_none(main_s, main_s->menu_setting->quit_but);
}