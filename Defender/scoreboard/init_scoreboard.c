/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init scoreboard
*/

#include "include/defender.h"

void init_scoreboard(game_t *main_s)
{
    main_s->scoreboard = malloc(sizeof(scoreboard_t));
    malloc_scoreboard(main_s);
    scoreboard_object_button(main_s);
    scoreboard_circle_button(main_s);
    scoreboard_text(main_s);
    main_s->ex_scene = 7;
    main_s->handler_scene = &handler_scoreboard;
    main_s->scene_destroy = &scoreboard_destroy;
}