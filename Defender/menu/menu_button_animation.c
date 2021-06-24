/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** manage animation of button
*/

#include "include/defender.h"

void rect_clic_call(game_t *main_s, rect_but *object, sfVector2f clic)
{
    if (is_rect_clic(main_s, object->button, clic))
        object->callback(main_s, *object);
}

void circle_clic_call(game_t *main_s, circle_but *object, sfVector2f clic)
{
    if (is_circle_clic(main_s, object->button, clic))
        object->callback(main_s, *object);
}

void check_menu_hover(game_t *main_s, sfVector2f ps_m)
{
    is_circle_hover(main_s, main_s->menu_scene->play_but->button, ps_m);
    is_circle_hover(main_s, main_s->menu_scene->quit_but->button, ps_m);
    is_rect_hover(main_s, main_s->menu_scene->sound_but->button, ps_m);
    is_rect_hover(main_s, main_s->menu_scene->music_but->button, ps_m);
    is_rect_hover(main_s, main_s->menu_scene->htp_but->button, ps_m);
    is_rect_hover(main_s, main_s->menu_scene->setting_but->button, ps_m);
    is_rect_hover(main_s, main_s->menu_scene->scoreboard_button->button, ps_m);
}

void check_menu_clic(game_t *main_s, sfVector2f pos_mouse)
{
    rect_clic_call(main_s, main_s->menu_scene->sound_but, pos_mouse);
    rect_clic_call(main_s, main_s->menu_scene->music_but, pos_mouse);
    rect_clic_call(main_s, main_s->menu_scene->setting_but, pos_mouse);
    rect_clic_call(main_s, main_s->menu_scene->htp_but, pos_mouse);
    rect_clic_call(main_s, main_s->menu_scene->scoreboard_button, pos_mouse);
    circle_clic_call(main_s, main_s->menu_scene->play_but, pos_mouse);
    circle_clic_call(main_s, main_s->menu_scene->quit_but, pos_mouse);
}