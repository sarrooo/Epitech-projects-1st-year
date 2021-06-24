/*
** EPITECH PROJECT, 2021
** game
** File description:
** game
*/

#include "./include/defender.h"

void loader_scene(game_t *game)
{
    if (game->current_scene == game->ex_scene) {
        return;
    }
    if (game->scene_destroy != NULL)
        game->scene_destroy(game);
    if (game->scene_config != NULL)
        game->scene_config(game);
}

void game_start(game_t *game)
{
    while (sfRenderWindow_isOpen(game->win)) {
        sfRenderWindow_clear(game->win, sfBlack);
        loader_scene(game);
        game->handler_scene(game);
        sfRenderWindow_display(game->win);
    }
}