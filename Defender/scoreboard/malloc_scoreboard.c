/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** malloc scoreboard scenes
*/

#include "include/defender.h"

void malloc_scoreboard(game_t *main_s)
{
    main_s->scoreboard->background = malloc(sizeof(object_t));
    main_s->scoreboard->plank = malloc(sizeof(object_t));
    main_s->scoreboard->dark = malloc(sizeof(object_t));
    main_s->scoreboard->quit_button = malloc(sizeof(circle_but));
    main_s->scoreboard->header = malloc(sizeof(text_t));
    main_s->scoreboard->first_place = malloc(sizeof(text_t));
    main_s->scoreboard->second_place = malloc(sizeof(text_t));
    main_s->scoreboard->third_place = malloc(sizeof(text_t));
    main_s->scoreboard->fourth_place = malloc(sizeof(text_t));
    main_s->scoreboard->fifth_place = malloc(sizeof(text_t));
}