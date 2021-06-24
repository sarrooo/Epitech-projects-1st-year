/*
** EPITECH PROJECT, 2021
** defender
** File description:
** animation spell
*/

#include "../include/defender.h"

void animation_spell_fire(game_t *game)
{
    game->map.time = game->map.time_base;
    game->map.time += get_time(game);
    sfIntRect rect = sfSprite_getTextureRect(game->map.fireball.sprite_spell);

    if (game->map.time > game->map.fireball.last_move + 0.2 && rect.left < 2800
    && game->map.fireball.animation == 1) {
        rect.left += 104;
        sfSprite_setTextureRect(game->map.fireball.sprite_spell, rect);
        if (rect.left > 2799) {
            game->map.fireball.animation = 0;
            rect.left = 0;
            sfSound_stop(game->map.fireball.sound);
            sfSprite_setTextureRect(game->map.fireball.sprite_spell, rect);
        }
        game->map.fireball.last_move = game->map.time;
    }
    if (game->map.fireball.animation == 1) {
        sfSprite_setScale(game->map.fireball.sprite_spell, (sfVector2f){2, 2});
        sfRenderWindow_drawSprite(game->win,
        game->map.fireball.sprite_spell, NULL);
    }
}

void animation_spell_freeze(game_t *game)
{
    game->map.time = game->map.time_base;
    game->map.time += get_time(game);
    sfIntRect rect = sfSprite_getTextureRect(game->map.freeze.sprite_spell);

    if (game->map.time > game->map.freeze.last_move + 0.3 && rect.left < 1300
    && game->map.freeze.animation == 1) {
        rect.left += 100;
        sfSprite_setTextureRect(game->map.freeze.sprite_spell, rect);
        if (rect.left > 1299) {
            game->map.freeze.animation = 0;
            rect.left = 0;
            sfSound_stop(game->map.freeze.sound);
            sfSprite_setTextureRect(game->map.freeze.sprite_spell, rect);
        }
        game->map.freeze.last_move = game->map.time;
    }
    if (game->map.freeze.animation == 1) {
        sfSprite_setScale(game->map.freeze.sprite_spell, (sfVector2f){2, 2});
        sfRenderWindow_drawSprite(game->win,
        game->map.freeze.sprite_spell, NULL);
    }
}

void set_cooldown_fire(game_t *game)
{
    if (game->map.fireball.targeting == 1) {
        game->map.fireball.available = game->map.time + 15;
        sfSound_setVolume(game->map.fireball.sound, game->volume);
        sfSound_play(game->map.fireball.sound);
        sfSprite_setColor(game->map.fireball.icone,
        (sfColor){128, 128, 128, 255});
        sfSprite_setPosition(game->map.fireball.sprite_spell,
        (sfVector2f){game->mouse_pos.x - 100, game->mouse_pos.y - 350});
        game->map.fireball.last_move = game->map.time;
        game->map.fireball.animation = 1;
    }
}

void set_cooldown_freeze(game_t *game)
{
    if (game->map.freeze.targeting == 1) {
        game->map.freeze.available = game->map.time + 15;
        sfSound_setVolume(game->map.freeze.sound, game->volume);
        sfSound_play(game->map.freeze.sound);
        sfSprite_setColor(game->map.freeze.icone,
        (sfColor){128, 128, 128, 255});
        sfSprite_setPosition(game->map.freeze.sprite_spell,
        (sfVector2f){game->mouse_pos.x - 100, game->mouse_pos.y - 350});
        game->map.freeze.last_move = game->map.time;
        game->map.freeze.animation = 1;
    }
}

void set_cooldown(game_t *game)
{
    game->map.time = game->map.time_base;
    game->map.time += get_time(game);
    set_cooldown_fire(game);
    set_cooldown_freeze(game);
}