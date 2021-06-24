/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init circle button for setting menu
*/

#include "include/defender.h"

void init_setting_music(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.callback = reduce_music_volume;
    info.radian = 25;
    info.path = "asset/button/button_minus.png";
    info.pos.x = ((size_win.x / 2) - 110) + 135;
    info.pos.y = ((size_win.y / 2) - 23) - 55;
    circle_button(main_s, info, main_s->menu_setting->music_minus);
    info.callback = raise_music_volume;
    info.path = "asset/button/button_plus.png";
    info.pos.x = ((size_win.x / 2) - 110) + 375;
    circle_button(main_s, info, main_s->menu_setting->music_plus);
}

void init_setting_rate(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.radian = 25;
    info.callback = reduce_framerate;
    info.path = "asset/button/button_minus.png";
    info.pos.x = ((size_win.x / 2) - 110) + 135;
    info.pos.y = ((size_win.y / 2) - 23) + 95;
    circle_button(main_s, info, main_s->menu_setting->rate_minus);
    info.callback = raise_framerate;
    info.path = "asset/button/button_plus.png";
    info.pos.x = ((size_win.x / 2) - 110) + 375;
    circle_button(main_s, info, main_s->menu_setting->rate_plus);
}

void setting_circle_button(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.callback = quit_setting;
    info.radian = 35;
    info.path = "asset/button/close.png";
    info.pos.x = ((size_win.x / 2) - 338) + 615;
    info.pos.y = (size_win.y / 2) - 230;
    circle_button(main_s, info, main_s->menu_setting->quit_but);
    init_setting_music(main_s);
    init_setting_rate(main_s);
}