/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** manage clic and animation of button
*/

#include "include/defender.h"

void check_pause_hover(game_t *main_s, sfVector2f pos_mouse)
{
    is_circle_hover(main_s, main_s->menu_pause->music_minus->button, pos_mouse);
    is_circle_hover(main_s, main_s->menu_pause->music_plus->button, pos_mouse);
    is_circle_hover(main_s, main_s->menu_pause->rate_plus->button, pos_mouse);
    is_circle_hover(main_s, main_s->menu_pause->rate_minus->button, pos_mouse);
    is_circle_hover(main_s, main_s->menu_pause->resume->button, pos_mouse);
    is_rect_hover(main_s, main_s->menu_pause->quit->button, pos_mouse);
    is_rect_hover(main_s, main_s->menu_pause->menu->button, pos_mouse);
}

void check_pause_clic(game_t *main_s, sfVector2f pos_mouse)
{
    rect_clic_call(main_s, main_s->menu_pause->quit, pos_mouse);
    rect_clic_call(main_s, main_s->menu_pause->menu, pos_mouse);
    circle_clic_call(main_s, main_s->menu_pause->music_minus, pos_mouse);
    circle_clic_call(main_s, main_s->menu_pause->music_plus, pos_mouse);
    circle_clic_call(main_s, main_s->menu_pause->rate_minus, pos_mouse);
    circle_clic_call(main_s, main_s->menu_pause->rate_plus, pos_mouse);
    circle_clic_call(main_s, main_s->menu_pause->resume, pos_mouse);
}