/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** set button to orignal status
*/

#include "include/defender.h"

void scoreboard_check_button_none(game_t *main_s)
{
    animation_circle_none(main_s, main_s->scoreboard->quit_button);
}