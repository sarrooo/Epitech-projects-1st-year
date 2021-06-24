/*
** EPITECH PROJECT, 2021
** defender
** File description:
** destroy towers data
*/

#include "../include/defender.h"

void destroy_towers_data(game_t *game)
{
    free(game->map.stats);
}