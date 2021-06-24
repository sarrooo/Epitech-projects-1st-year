/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init circle button for win screen
*/

#include "include/defender.h"

void win_screen_circle_button(game_t *main_s)
{
    info_t info;

    info.callback = close_window_win_screen;
    info.radian = 35;
    info.path = "asset/button/close.png";
    info.pos.x = 1840;
    info.pos.y = 10;
    circle_button(main_s, info, main_s->win_screen->quit_button);
}