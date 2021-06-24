/*
** EPITECH PROJECT, 2021
** defender
** File description:
** clock tools
*/

#include "../include/defender.h"

float get_time(game_t *game)
{
    return (sfClock_getElapsedTime(game->map.clock).microseconds / 1000000.0);
}