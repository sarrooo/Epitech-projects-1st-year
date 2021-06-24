/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** manage animation of button
*/

#include "include/defender.h"

void check_scoreboard_hover(game_t *main_s, sfVector2f pos_mous)
{
    is_circle_hover(main_s, main_s->scoreboard->quit_button->button, pos_mous);
}

void check_scoreboard_clic(game_t *main_s, sfVector2f pos_mouse)
{
    circle_clic_call(main_s, main_s->scoreboard->quit_button, pos_mouse);
}