/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init object menu setting
*/

#include "include/defender.h"

void init_setting_rope(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.scale.x = 0.75;
    info.scale.y = 0.75;
    info.path = "asset/rope.png";
    info.pos.x = (size_win.x / 2) - 200 - 15;
    info.pos.y = 0;
    init_object(main_s, info, main_s->menu_setting->rope_1);
    info.pos.x = (size_win.x / 2) + 200;
    init_object(main_s, info, main_s->menu_setting->rope_2);
}

void init_setting_bar(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.scale.x = 0.75;
    info.scale.y = 0.75;
    info.path = "asset/bar_bg.png";
    info.pos.x = ((size_win.x / 2) - 110) + 170;
    info.pos.y = ((size_win.y / 2) - 23) - 50;
    init_object(main_s, info, main_s->menu_setting->music_bar_bg);
    info.path = "asset/bar_bg.png";
    info.pos.x = ((size_win.x / 2) - 110) + 170;
    info.pos.y = ((size_win.y / 2) - 23) + 100;
    init_object(main_s, info, main_s->menu_setting->rate_bar_bg);
    info.path = "asset/bar.png";
    info.scale.x = 1.11;
    info.scale.y = 1.11;
    info.pos.x = ((size_win.x / 2) - 110) + 170;
    info.pos.y = ((size_win.y / 2) - 23) - 50;
    init_object(main_s, info, main_s->menu_setting->music_bar);
    info.pos.y = ((size_win.y / 2) - 23) + 100;
    init_object(main_s, info, main_s->menu_setting->rate_bar);
}

void setting_object_button(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.scale = (sfVector2f){1, 1};
    info.path = "asset/bg/dark.png";
    info.pos = (sfVector2f){0, 0};
    init_object(main_s, info, main_s->menu_setting->dark);
    info.path = "asset/bg/bg.png";
    init_object(main_s, info, main_s->menu_setting->background);
    info.scale = (sfVector2f){0.7, 0.7};
    info.path = "asset/bg/table.png";
    info.pos.x = ((size_win.x / 2) - 338);
    info.pos.y = (size_win.y / 2) - 219;
    init_object(main_s, info, main_s->menu_setting->plank);
    info.path = "asset/logo/header_settings.png";
    info.pos.x = ((size_win.x / 2) - 137);
    info.pos.y = (size_win.y / 2) - 230;
    init_object(main_s, info, main_s->menu_setting->header);
    init_setting_rope(main_s);
    init_setting_bar(main_s);
}