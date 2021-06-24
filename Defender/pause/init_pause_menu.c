/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init pause menu
*/

#include "include/defender.h"

void init_pause_scenes(game_t *main_s)
{
    main_s->menu_pause = malloc(sizeof(pause_t));
    malloc_pause(main_s);
    pause_object_button(main_s);
    pause_circle_button(main_s);
    pause_rect_button(main_s);
    pause_text(main_s);
}