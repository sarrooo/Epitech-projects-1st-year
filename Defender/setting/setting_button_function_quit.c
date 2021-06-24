/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** quit setting
*/

#include "include/defender.h"

void quit_setting(game_t *main_s)
{
    animation_circle_clic(main_s, *main_s->menu_setting->quit_but);
    main_s->current_scene = MENU;
    main_s->scene_config = &init_menu_scenes;
}