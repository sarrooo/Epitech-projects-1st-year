/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** resume game pause menu
*/

#include "include/defender.h"

void resume_game(game_t *main_s)
{
    main_s->map.paused = -1;
    animation_circle_clic(main_s, *main_s->menu_pause->resume);
}