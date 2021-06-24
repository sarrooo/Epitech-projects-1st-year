/*
** EPITECH PROJECT, 2021
** my_defende
** File description:
** init circle button for main menu
*/

#include "include/defender.h"

void menu_circle_button(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.callback = play_game;
    info.radian = 110;
    info.path = "asset/button/play.png";
    info.pos.x = (size_win.x / 2) - 110;
    info.pos.y = (size_win.y / 2) - 110;
    circle_button(main_s, info, main_s->menu_scene->play_but);
    info.callback = close_window;
    info.radian = 35;
    info.path = "asset/button/close.png";
    info.pos.x = 1840;
    info.pos.y = 10;
    circle_button(main_s, info, main_s->menu_scene->quit_but);
}