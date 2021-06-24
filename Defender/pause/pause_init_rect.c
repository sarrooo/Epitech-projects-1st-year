/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init rect button for pause menu
*/

#include "include/defender.h"

void pause_rect_button(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.callback = menu_game_pause;
    info.size = int_to_sfvector2f(146, 145);
    info.path = "asset/button/button_left.png";
    info.pos.x = ((size_win.x / 2) - 90) - 185;
    info.pos.y = (size_win.y / 2) - 90 + 90;
    rect_button(main_s, info, main_s->menu_pause->menu);
    info.callback = quit_game_pause;
    info.size = int_to_sfvector2f(146, 145);
    info.path = "asset/button/button_exit.png";
    info.pos.x = ((size_win.x / 2) - 90) + 220;
    info.pos.y = (size_win.y / 2) - 90 + 90;
    rect_button(main_s, info, main_s->menu_pause->quit);
}