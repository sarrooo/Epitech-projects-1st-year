/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** malloc setting menu
*/

#include "include/defender.h"

void malloc_object_setting(game_t *main_s)
{
    main_s->menu_setting->dark = malloc(sizeof(object_t));
    main_s->menu_setting->rope_1 = malloc(sizeof(object_t));
    main_s->menu_setting->rope_2 = malloc(sizeof(object_t));
    main_s->menu_setting->plank = malloc(sizeof(object_t));
    main_s->menu_setting->header = malloc(sizeof(object_t));
    main_s->menu_setting->music_bar_bg = malloc(sizeof(object_t));
    main_s->menu_setting->music_bar = malloc(sizeof(object_t));
    main_s->menu_setting->rate_bar_bg = malloc(sizeof(object_t));
    main_s->menu_setting->rate_bar = malloc(sizeof(object_t));
}

void malloc_setting(game_t *main_s)
{
    main_s->menu_setting = malloc(sizeof(setting_t));
    malloc_object_setting(main_s);
    main_s->menu_setting->quit_but = malloc(sizeof(circle_but));
    main_s->menu_setting->on_off_button = malloc(sizeof(rect_but));
    main_s->menu_setting->on_off_button_2 = malloc(sizeof(rect_but));
    main_s->menu_setting->music_minus = malloc(sizeof(circle_but));
    main_s->menu_setting->music_plus = malloc(sizeof(circle_but));
    main_s->menu_setting->rate_minus = malloc(sizeof(circle_but));
    main_s->menu_setting->rate_plus = malloc(sizeof(circle_but));
    main_s->menu_setting->music_txt = malloc(sizeof(text_t));
    main_s->menu_setting->sound_txt = malloc(sizeof(text_t));
    main_s->menu_setting->music_volume = malloc(sizeof(text_t));
    main_s->menu_setting->graphic = malloc(sizeof(text_t));
    main_s->menu_setting->background = malloc(sizeof(object_t));
}