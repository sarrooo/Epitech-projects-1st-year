/*
** EPITECH PROJECT, 2021
** my_defende
** File description:
** init circle button for main menu
*/

#include "include/defender.h"

void scoreboard_circle_button(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.callback = return_to_menu_scoreboard;
    info.radian = 40;
    info.path = "asset/button/close.png";
    info.pos.x = 1200;
    info.pos.y = (size_win.y / 2) - (400 * 1);
    circle_button(main_s, info, main_s->scoreboard->quit_button);
}