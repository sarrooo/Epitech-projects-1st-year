/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init object for main menu
*/

#include "include/defender.h"

void scoreboard_object_button(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.scale = (sfVector2f){1, 1};
    info.path = "asset/bg/bg.png";
    info.pos.x = 0;
    info.pos.y = 0;
    init_object(main_s, info, main_s->scoreboard->background);
    info.path = "asset/bg/dark.png";
    init_object(main_s, info, main_s->scoreboard->dark);
    info.path = "asset/bg/table_big.png";
    info.pos.x = ((size_win.x / 2) - (319 * 1));
    info.pos.y = (size_win.y / 2) - (400 * 1);
    init_object(main_s, info, main_s->scoreboard->plank);
}