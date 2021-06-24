/*
** EPITECH PROJECT, 2021
** defender
** File description:
** htp defender
*/

#include "../include/defender.h"

void handle_target_fire(game_t *game)
{
    sfVector2f fire_p = sfSprite_getPosition(game->map.fireball.icone);

    game->map.time = game->map.time_base;
    game->map.time += get_time(game);
    set_cooldown_fire(game);
    game->map.fireball.targeting = -1;
    game->map.freeze.targeting = -1;
    if (game->mouse_pos.x <= fire_p.x + 100 && game->mouse_pos.x >= fire_p.x
    && game->mouse_pos.y <= fire_p.y + 100 && game->mouse_pos.y >= fire_p.y) {
        sfSprite_setScale(game->map.fireball.icone, (sfVector2f){0.5, 0.5});
        sfSprite_setPosition(game->map.fireball.icone, (sfVector2f){25, 25});
        if (game->map.fireball.available < game->map.time)
            game->map.fireball.targeting *= -1;
    }
}

void handle_target_freeze(game_t *game)
{
    sfVector2f frz_p = sfSprite_getPosition(game->map.freeze.icone);
    game->map.time = game->map.time_base;
    game->map.time += get_time(game);
    set_cooldown_freeze(game);
    game->map.fireball.targeting = -1;
    game->map.freeze.targeting = -1;
    if (game->mouse_pos.x <= frz_p.x + 100 && game->mouse_pos.x >= frz_p.x
    && game->mouse_pos.y <= frz_p.y + 100 && game->mouse_pos.y >= frz_p.y) {
        sfSprite_setScale(game->map.freeze.icone, (sfVector2f){0.5, 0.5});
        sfSprite_setPosition(game->map.freeze.icone, (sfVector2f){25, 125});
        if (game->map.freeze.available < game->map.time)
            game->map.freeze.targeting *= -1;
    }
}

void handle_over_fire(game_t *game)
{
    sfVector2f fr_p = sfSprite_getPosition(game->map.fireball.icone);
    game->map.time = game->map.time_base;
    game->map.time += get_time(game);

    if (game->map.fireball.available < game->map.time) {
        if (game->mouse_pos.x <= fr_p.x + 100 && game->mouse_pos.x >= fr_p.x
        && game->mouse_pos.y <= fr_p.y + 100 && game->mouse_pos.y >= fr_p.y) {
            sfSprite_setColor(game->map.fireball.icone, sfRed);
        } else {
            sfSprite_setColor(game->map.fireball.icone, sfWhite);
        }
    }
}

void handle_over_freeze(game_t *game)
{
    sfVector2f fz_p = sfSprite_getPosition(game->map.freeze.icone);
    game->map.time = game->map.time_base;
    game->map.time += get_time(game);
    if (game->map.freeze.available < game->map.time) {
        if (game->mouse_pos.x <= fz_p.x + 100 && game->mouse_pos.x >= fz_p.x
        && game->mouse_pos.y <= fz_p.y + 100 && game->mouse_pos.y >= fz_p.y) {
            sfSprite_setColor(game->map.freeze.icone, sfBlue);
        } else {
            sfSprite_setColor(game->map.freeze.icone, sfWhite);
        }
    }
}