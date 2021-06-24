/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** destroy menu scene
*/

#include "include/defender.h"

void scoreboard_destroy(game_t *main_s)
{
    destroy_circle(main_s->scoreboard->quit_button);
    destroy_object(main_s->scoreboard->dark);
    destroy_object(main_s->scoreboard->plank);
    destroy_object(main_s->scoreboard->background);
    destroy_text(main_s->scoreboard->header);
    destroy_text(main_s->scoreboard->first_place);
    destroy_text(main_s->scoreboard->second_place);
    destroy_text(main_s->scoreboard->third_place);
    destroy_text(main_s->scoreboard->fourth_place);
    destroy_text(main_s->scoreboard->fifth_place);
    free(main_s->scoreboard);
}