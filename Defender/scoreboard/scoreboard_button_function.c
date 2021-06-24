/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** function for button on scoreboard scenes 
*/

#include "include/defender.h"

void return_to_menu_scoreboard(game_t *main_s)
{
    animation_circle_clic(main_s, *main_s->scoreboard->quit_button);
    main_s->current_scene = 1;
    main_s->scene_config = &init_menu_scenes;
}