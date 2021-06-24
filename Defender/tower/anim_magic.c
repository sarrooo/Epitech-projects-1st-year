/*
** EPITECH PROJECT, 2021
** defender
** File description:
** anim magic
*/

#include "../include/defender.h"

void game_animation(game_t *game, int it)
{
    sfIntRect theRect = sfSprite_getTextureRect(game->map.towers[it].sprite);

    game->map.time = game->map.time_base;
    game->map.time += get_time(game);
    if (game->map.towers[it].timer + 0.2 < game->map.time) {
        theRect.left = 200;
        sfSprite_setTextureRect(game->map.towers[it].sprite, theRect);
    }
    if (game->map.towers[it].timer + 0.4 < game->map.time) {
        theRect.left = 400;
        sfSprite_setTextureRect(game->map.towers[it].sprite, theRect);
    }
    if (game->map.towers[it].timer + 0.6 < game->map.time) {
        theRect.left = 600;
        sfSprite_setTextureRect(game->map.towers[it].sprite, theRect);
    }
    if (game->map.towers[it].timer + 0.8 < game->map.time) {
        theRect.left = 0;
        sfSprite_setTextureRect(game->map.towers[it].sprite, theRect);
    }
}