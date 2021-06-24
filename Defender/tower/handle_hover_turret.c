/*
** EPITECH PROJECT, 2021
** defender
** File description:
** handle hover turret
*/

#include "../include/defender.h"

void handle_hover_spell(game_t *game)
{
    sfVector2f fr_p = sfSprite_getPosition(game->map.fireball.icone);
    sfVector2f fz_p = sfSprite_getPosition(game->map.freeze.icone);
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
    if (game->map.freeze.available < game->map.time) {
        if (game->mouse_pos.x <= fz_p.x + 100 && game->mouse_pos.x >= fz_p.x
        && game->mouse_pos.y <= fz_p.y + 100 && game->mouse_pos.y >= fz_p.y) {
            sfSprite_setColor(game->map.freeze.icone, sfBlue);
        } else {
            sfSprite_setColor(game->map.freeze.icone, sfWhite);
        }
    }
}

void handle_hover_turret(game_t *game)
{
    for (int i = 0; i < 7; i += 1) {
        if ((game->mouse_pos.x > game->map.turret_pos[i].x1 &&
        game->mouse_pos.x < game->map.turret_pos[i].x2) &&
        (game->mouse_pos.y > game->map.turret_pos[i].y1 &&
        game->mouse_pos.y < game->map.turret_pos[i].y2) &&
        game->map.towers[i].type == 0) {
            sfRenderWindow_drawSprite(game->win,
            game->map.turret_pos[i].sprite, NULL);
        }
    }
    return;
}