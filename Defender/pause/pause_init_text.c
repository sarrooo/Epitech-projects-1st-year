/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init text for pause menu
*/

#include "include/defender.h"

void pause_text(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.str = "Paused";
    info.path = "asset/font/Dimbo.ttf";
    info.pos.x = ((size_win.x / 2) - 90);
    info.pos.y = ((size_win.y / 2) - 220);
    info.size.x = 80;
    info.color = sfWhite;
    init_text(main_s, info, main_s->menu_pause->header);
    info.size.x = 40;
    info.str = "Sound volume";
    info.pos.x = ((size_win.x / 2) - 110) - 140;
    info.pos.y = ((size_win.y / 2) - 23) - 110;
    init_text(main_s, info, main_s->menu_pause->sound_volume);
    info.str = "Music volume";
    info.pos.x = ((size_win.x / 2) - 110) + 200;
    init_text(main_s, info, main_s->menu_pause->music_volume);
}