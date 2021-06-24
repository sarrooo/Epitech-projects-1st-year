/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init object for main menu
*/

#include "include/defender.h"

void menu_object_button(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.scale.x = 1;
    info.scale.y = 1;
    info.path = "asset/bg/bg.png";
    info.pos.x = 0;
    info.pos.y = 0;
    init_object(main_s, info, main_s->menu_scene->background);
    info.scale.x = 0.9;
    info.scale.y = 0.9;
    info.path = "asset/logo/logo_4.png";
    info.pos.x = (size_win.x / 2) - 525;
    info.pos.y = ((size_win.y / 2) - 150) - 250;
    init_object(main_s, info, main_s->menu_scene->logo);
}