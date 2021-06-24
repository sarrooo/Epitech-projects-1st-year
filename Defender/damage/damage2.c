/*
** EPITECH PROJECT, 2021
** defender
** File description:
** damage2
*/

#include "../include/defender.h"

int check_if_monster_is_in_range2(game_t *game, int it, int im)
{
    if (it == game->map.monster_wave->monster[im].electrise - 1) {
        game->map.monster_wave->monster[im].electrise = 0;
    }
}