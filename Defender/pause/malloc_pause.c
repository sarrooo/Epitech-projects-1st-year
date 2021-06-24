/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** malloc pause menu
*/

#include "include/defender.h"

void malloc_pause(game_t *main_s)
{
    main_s->menu_pause = malloc(sizeof(pause_t));
    main_s->menu_pause->dark = malloc(sizeof(object_t));
    main_s->menu_pause->rope_1 = malloc(sizeof(object_t));
    main_s->menu_pause->rope_2 = malloc(sizeof(object_t));
    main_s->menu_pause->music_bar_bg = malloc(sizeof(object_t));
    main_s->menu_pause->music_bar = malloc(sizeof(object_t));
    main_s->menu_pause->rate_bar_bg = malloc(sizeof(object_t));
    main_s->menu_pause->rate_bar = malloc(sizeof(object_t));
    main_s->menu_pause->plank = malloc(sizeof(object_t));
    main_s->menu_pause->resume = malloc(sizeof(circle_but));
    main_s->menu_pause->music_plus = malloc(sizeof(circle_but));
    main_s->menu_pause->music_minus = malloc(sizeof(circle_but));
    main_s->menu_pause->rate_plus = malloc(sizeof(circle_but));
    main_s->menu_pause->rate_minus = malloc(sizeof(circle_but));
    main_s->menu_pause->quit = malloc(sizeof(rect_but));
    main_s->menu_pause->menu = malloc(sizeof(rect_but));
    main_s->menu_pause->header = malloc(sizeof(text_t));
    main_s->menu_pause->music_volume = malloc(sizeof(text_t));
    main_s->menu_pause->sound_volume = malloc(sizeof(text_t));
}