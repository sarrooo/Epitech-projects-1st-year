/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init object for pause menu
*/

#include "include/defender.h"

void init_pause_rope(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.scale.x = 0.75;
    info.scale.y = 0.75;
    info.path = "asset/rope.png";
    info.pos.x = (size_win.x / 2) - 200 - 15;
    info.pos.y = 0;
    init_object(main_s, info, main_s->menu_pause->rope_1);
    info.pos.x = (size_win.x / 2) + 200;
    init_object(main_s, info, main_s->menu_pause->rope_2);
}

void init_pause_bar(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.scale.x = 0.75;
    info.scale.y = 0.75;
    info.path = "asset/bar_bg.png";
    info.pos.x = ((size_win.x / 2) - 110) + 170;
    info.pos.y = ((size_win.y / 2) - 23) - 65;
    init_object(main_s, info, main_s->menu_pause->music_bar_bg);
    info.path = "asset/bar_bg.png";
    info.pos.x = ((size_win.x / 2) - 110) - 170;
    init_object(main_s, info, main_s->menu_pause->rate_bar_bg);
    info.path = "asset/bar.png";
    info.scale.x = 1.11;
    info.scale.y = 1.11;
    info.pos.x = ((size_win.x / 2) - 110) + 170;
    init_object(main_s, info, main_s->menu_pause->music_bar);
    info.pos.x = ((size_win.x / 2) - 110) - 170;
    init_object(main_s, info, main_s->menu_pause->rate_bar);
}

void pause_object_button(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.scale.x = 1;
    info.scale.y = 1;
    info.path = "asset/bg/dark.png";
    info.pos.x = 0;
    info.pos.y = 0;
    init_object(main_s, info, main_s->menu_pause->dark);
    info.scale.x = 0.7;
    info.scale.y = 0.7;
    info.path = "asset/bg/table.png";
    info.pos.x = ((size_win.x / 2) - 338);
    info.pos.y = (size_win.y / 2) - 219;
    init_object(main_s, info, main_s->menu_pause->plank);
    init_pause_bar(main_s);
    init_pause_rope(main_s);
}