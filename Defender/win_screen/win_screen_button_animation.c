/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** manage clic and animation of button
*/

#include "include/defender.h"

void check_win_screen_hover(game_t *main_s, sfVector2f pos_mouse)
{
    is_rect_hover(main_s, main_s->win_screen->replay_button->button, pos_mouse);
    is_rect_hover(main_s, main_s->win_screen->menu_button->button, pos_mouse);
    is_circle_hover(main_s, main_s->win_screen->quit_button->button, pos_mouse);
}

void check_win_screen_clic(game_t *main_s, sfVector2f pos_mouse)
{
    rect_clic_call(main_s, main_s->win_screen->replay_button, pos_mouse);
    rect_clic_call(main_s, main_s->win_screen->menu_button, pos_mouse);
    circle_clic_call(main_s, main_s->win_screen->quit_button, pos_mouse);
}