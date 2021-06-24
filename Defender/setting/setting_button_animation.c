/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** manage button on setting menu animation
*/

#include "include/defender.h"

void check_setting_hover(game_t *main_s, sfVector2f pos_mouse)
{
    is_circle_hover(main_s,
    main_s->menu_setting->rate_minus->button, pos_mouse);
    is_circle_hover(main_s,
    main_s->menu_setting->rate_plus->button, pos_mouse);
    is_circle_hover(main_s,
    main_s->menu_setting->music_plus->button, pos_mouse);
    is_circle_hover(main_s,
    main_s->menu_setting->music_minus->button, pos_mouse);
    is_circle_hover(main_s,
    main_s->menu_setting->quit_but->button, pos_mouse);
    is_rect_hover(main_s,
    main_s->menu_setting->on_off_button->button, pos_mouse);
    is_rect_hover(main_s,
    main_s->menu_setting->on_off_button_2->button, pos_mouse);
}

void check_setting_clic(game_t *main_s, sfVector2f pos_mouse)
{
    rect_clic_call(main_s, main_s->menu_setting->on_off_button, pos_mouse);
    rect_clic_call(main_s, main_s->menu_setting->on_off_button_2, pos_mouse);
    circle_clic_call(main_s, main_s->menu_setting->music_plus, pos_mouse);
    circle_clic_call(main_s, main_s->menu_setting->music_minus, pos_mouse);
    circle_clic_call(main_s, main_s->menu_setting->rate_plus, pos_mouse);
    circle_clic_call(main_s, main_s->menu_setting->rate_minus, pos_mouse);
    circle_clic_call(main_s, main_s->menu_setting->quit_but, pos_mouse);
}