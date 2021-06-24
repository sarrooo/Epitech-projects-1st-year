/*
** EPITECH PROJECT, 2021
** defender
** File description:
** event_move
*/

#include "../include/defender.h"

void handle_move(game_t *game, sfMouseMoveEvent event)
{
    const sfView *view = sfRenderWindow_getView(game->win);

    game->mouse_pos = sfRenderWindow_mapPixelToCoords(game->win,
    (sfVector2i){event.x, event.y}, view);
    sfSprite_setPosition(game->map.fireball.cursor,
    (sfVector2f){game->mouse_pos.x - 100, game->mouse_pos.y- 100});
    sfSprite_setPosition(game->map.freeze.cursor,
    (sfVector2f){game->mouse_pos.x - 100, game->mouse_pos.y- 100});
    return;
}