/*
** EPITECH PROJECT, 2021
** defender
** File description:
** display_turret
*/

#include "../include/defender.h"

void display_turrets(game_t *game)
{
    for (int i = 0; i < 7; i++) {
        if (game->map.towers[i].type != 0) {
            sfRenderWindow_drawSprite(game->win,
            game->map.towers[i].sprite, NULL);
        }
    }
}