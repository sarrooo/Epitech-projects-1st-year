/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** destroy setting scenes
*/

#include "include/defender.h"

void setting_destroy(game_t *main_s)
{
    destroy_object(main_s->menu_setting->dark);
    destroy_object(main_s->menu_setting->plank);
    destroy_object(main_s->menu_setting->header);
    destroy_object(main_s->menu_setting->rope_1);
    destroy_object(main_s->menu_setting->rope_2);
    destroy_object(main_s->menu_setting->music_bar_bg);
    destroy_object(main_s->menu_setting->music_bar);
    destroy_object(main_s->menu_setting->rate_bar_bg);
    destroy_object(main_s->menu_setting->rate_bar);
    destroy_circle(main_s->menu_setting->quit_but);
    destroy_circle(main_s->menu_setting->music_minus);
    destroy_circle(main_s->menu_setting->music_plus);
    destroy_circle(main_s->menu_setting->rate_minus);
    destroy_circle(main_s->menu_setting->rate_plus);
    destroy_rect(main_s->menu_setting->on_off_button);
    destroy_rect(main_s->menu_setting->on_off_button_2);
    destroy_text(main_s->menu_setting->music_txt);
    destroy_text(main_s->menu_setting->music_volume);
    destroy_text(main_s->menu_setting->sound_txt);
    destroy_text(main_s->menu_setting->graphic);
}