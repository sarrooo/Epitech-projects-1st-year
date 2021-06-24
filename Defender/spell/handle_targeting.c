/*
** EPITECH PROJECT, 2021
** defender
** File description:
** handle_targeting
*/

#include "../include/defender.h"

void spell_cursor(game_t *game)
{
    if (game->map.fireball.targeting == 1 || game->map.freeze.targeting == 1) {
        sfRenderWindow_setMouseCursorVisible(game->win, sfFalse);
        if (game->map.fireball.targeting == 1)
            sfRenderWindow_drawSprite(game->win, game->map.fireball.cursor,
            NULL);
        if (game->map.freeze.targeting == 1)
            sfRenderWindow_drawSprite(game->win, game->map.freeze.cursor,
            NULL);
    } else {
        sfRenderWindow_setMouseCursorVisible(game->win, sfTrue);
    }
}

void handle_targeting2(game_t *game)
{
    game->map.time = game->map.time_base;
    game->map.time += get_time(game);
}

void handle_targeting(game_t *game)
{
    sfVector2f fire_p = sfSprite_getPosition(game->map.fireball.icone);
    sfVector2f frz_p = sfSprite_getPosition(game->map.freeze.icone);

    handle_targeting2(game);
    set_cooldown(game);
    game->map.fireball.targeting = -1;
    game->map.freeze.targeting = -1;
    if (game->mouse_pos.x <= fire_p.x + 100 && game->mouse_pos.x >= fire_p.x
    && game->mouse_pos.y <= fire_p.y + 100 && game->mouse_pos.y >= fire_p.y) {
        sfSprite_setScale(game->map.fireball.icone, (sfVector2f){0.5, 0.5});
        sfSprite_setPosition(game->map.fireball.icone, (sfVector2f){25, 25});
        if (game->map.fireball.available < game->map.time)
            game->map.fireball.targeting *= -1;
    }
    if (game->mouse_pos.x <= frz_p.x + 100 && game->mouse_pos.x >= frz_p.x
    && game->mouse_pos.y <= frz_p.y + 100 && game->mouse_pos.y >= frz_p.y) {
        sfSprite_setScale(game->map.freeze.icone, (sfVector2f){0.5, 0.5});
        sfSprite_setPosition(game->map.freeze.icone, (sfVector2f){25, 125});
        if (game->map.freeze.available < game->map.time)
            game->map.freeze.targeting *= -1;
    }
}