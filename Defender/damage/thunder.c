/*
** EPITECH PROJECT, 2021
** defender
** File description:
** damage
*/

#include "../include/defender.h"

void put_attack(game_t *game)
{
    game->map.time = game->map.time_base;
    game->map.time += get_time(game);
    for (int j = 0; j < 7; j += 1) {
        if ((game->map.towers[j].type == MAGICIAN_1 ||
        game->map.towers[j].type == MAGICIAN_2) &&
        game->map.towers[j].in_attack == 2) {
            game->map.towers[j].in_attack = 1;
            sfSound_setVolume(game->map.zap, game->volume);
            sfSound_play(game->map.zap);
        }
        if ((game->map.towers[j].type == MAGICIAN_1 ||
        game->map.towers[j].type == MAGICIAN_2) &&
        game->map.towers[j].timer + 1.1 < game->map.time) {
            game->map.towers[j].in_attack = 0;
        }
        if ((game->map.towers[j].type == MAGICIAN_1 ||
        game->map.towers[j].type == MAGICIAN_2)) {
            game_animation(game, j);
        }
    }
}

void apply_thunder(game_t *game, int it, int im)
{
    game->map.time = game->map.time_base;
    game->map.time += get_time(game);
    game->map.monster_wave->monster[im].electrise = it + 1;
    game->map.towers[it].timer = game->map.time;
    game->map.towers[it].in_attack = 2;
    game->map.monster_wave->monster[im].health -= game->map.towers[it].damage;
}

void init_thunder(game_t *game, int it)
{
    game->map.towers[it].thunder = sfSprite_create();
    sfSprite_setTexture(game->map.towers[it].thunder,
    game->map.towers[it].t_projectile, sfTrue);
}

void destroy_thunder(game_t *game, int it)
{
    sfSprite_destroy(game->map.towers[it].thunder);
}