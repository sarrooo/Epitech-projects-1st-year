/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** resume game pause menu
*/

#include "include/defender.h"

void menu_game_pause(game_t *main_s)
{
    animation_rect_clic(main_s, *main_s->menu_pause->menu);
    main_s->map.paused = -1;
    main_s->current_scene = MENU;
    main_s->scene_config = &init_menu_scenes;
}