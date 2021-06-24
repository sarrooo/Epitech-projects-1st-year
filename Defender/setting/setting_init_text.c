/*
** EPITECH PROJECT, 2021
** my_defende
** File description:
** init text for setting
*/

#include "include/defender.h"

void setting_text(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.str = "Music";
    info.path = "asset/font/Dimbo.ttf";
    info.pos.x = ((size_win.x / 2) - 65) - 235;
    info.pos.y = ((size_win.y / 2) - 31) - 60;
    info.size.x = 50;
    info.color = sfWhite;
    init_text(main_s, info, main_s->menu_setting->music_txt);
    info.str = "Sound";
    info.pos.y = ((size_win.y / 2) - 31) + 90;
    init_text(main_s, info, main_s->menu_setting->sound_txt);
    info.str = "Music volume";
    info.pos.x = ((size_win.x / 2) - 110) + 170;
    info.pos.y = ((size_win.y / 2) - 23) - 110;
    init_text(main_s, info, main_s->menu_setting->music_volume);
    info.str = "Framerate";
    info.pos.x = ((size_win.x / 2) - 110) + 190;
    info.pos.y = ((size_win.y / 2) - 23) + 40;
    init_text(main_s, info, main_s->menu_setting->graphic);
}