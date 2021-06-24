/*
** EPITECH PROJECT, 2021
** defender
** File description:
** destroy data
*/

#include "../include/defender.h"

void destroy_data(game_t *game)
{
    sfSprite_destroy(game->map.data->s_gold);
    sfSprite_destroy(game->map.data->s_wave);
    sfTexture_destroy(game->map.data->t_gold);
    sfTexture_destroy(game->map.data->t_wave);
    sfFont_destroy(game->map.data->font);
    sfText_destroy(game->map.data->gold);
    sfText_destroy(game->map.data->life);
    sfText_destroy(game->map.data->wave);
    free(game->map.data);
}