/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** manage main menu
*/

#include "include/defender.h"

void init_menu_scenes(game_t *main_s)
{
    main_s->menu_scene = malloc(sizeof(menu_t));
    malloc_menu(main_s);
    menu_object_button(main_s);
    menu_circle_button(main_s);
    menu_rect_button(main_s);
    update_music_button_menu(main_s);
    update_sound_button_menu(main_s);
    main_s->ex_scene = MENU;
    main_s->handler_scene = &handler_menu;
    main_s->scene_destroy = &menu_destroy;
}