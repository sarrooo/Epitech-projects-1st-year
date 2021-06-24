/*
** EPITECH PROJECT, 2021
** defender
** File description:
** check integrity of data
*/

#include "../include/defender.h"

void check_integrity_of_data(game_t *game)
{
    if (game->map.stats->archery1.damage < 1 ||
    game->map.stats->archery2.damage < 1 ||
    game->map.stats->magic1.damage < 1 || game->map.stats->magic2.damage < 1
    || game->map.stats->archery1.range < 150 ||
    game->map.stats->archery1.range > 500 ||
    game->map.stats->archery2.range < 150 ||
    game->map.stats->archery2.range > 500 ||
    game->map.stats->magic1.range < 150 || game->map.stats->magic1.range > 500
    || game->map.stats->magic2.range < 150 ||
    game->map.stats->magic2.range > 500)
        init_default_settings(game);
}