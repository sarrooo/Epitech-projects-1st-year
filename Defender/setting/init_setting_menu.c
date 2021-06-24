/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** create setting menu
*/

#include "include/defender.h"

void init_setting_scenes(game_t *main_s)
{
    malloc_setting(main_s);
    setting_object_button(main_s);
    setting_circle_button(main_s);
    setting_rect_button(main_s);
    setting_text(main_s);
    rect_music_bar(main_s->music, main_s->menu_setting->music_bar);
    rect_rate_bar(main_s, main_s->menu_setting->rate_bar);
    update_button_sound_setting(main_s);
    update_button_music_setting(main_s);
    main_s->ex_scene = SETTINGS;
    main_s->handler_scene = &handler_setting;
    main_s->scene_destroy = &setting_destroy;
}