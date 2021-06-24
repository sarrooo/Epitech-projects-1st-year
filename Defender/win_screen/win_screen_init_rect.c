/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init rect button for win screen
*/

#include "include/defender.h"

void win_screen_rect_button(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.callback = return_to_menu;
    info.size = int_to_sfvector2f(146, 145);
    info.path = "asset/button/button_menu.png";
    info.pos.x = ((size_win.x / 2) - 73) - 100;
    info.pos.y = ((size_win.y / 2) - 72) + 350;
    rect_button(main_s, info, main_s->win_screen->menu_button);
    info.path = "asset/button/button_restart.png";
    info.callback = restart_game;
    info.pos.x = ((size_win.x / 2) - 73) + 106;
    info.pos.y = ((size_win.y / 2) - 72) + 350;
    rect_button(main_s, info, main_s->win_screen->replay_button);
}