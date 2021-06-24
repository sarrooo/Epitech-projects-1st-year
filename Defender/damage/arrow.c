/*
** EPITECH PROJECT, 2021
** defender
** File description:
** arrow
*/

#include "../include/defender.h"

void set_step(game_t *game, int it, int im, double angle)
{
    sfVector2f pos_mob =
    sfSprite_getPosition(game->map.monster_wave->monster[im].sprite);
    sfVector2f pos_tow = game->map.towers[it].position;

    game->map.towers[it].arrow->step_x =
    (pos_tow.x - pos_mob.x) / game->map.towers[it].arrow->step_total;
    game->map.towers[it].arrow->step_y =
    (pos_tow.y - pos_mob.y) / game->map.towers[it].arrow->step_total;
    sfSound_setVolume(game->map.bow, game->volume);
    sfSound_play(game->map.bow);
    game->map.towers[it].arrow->target = im;
}

void init_arrow(game_t *game, int it, int im, double angle)
{
    sfVector2f pos_tow = game->map.towers[it].position;
    pos_tow.x += 100;
    pos_tow.y += 100;

    game->map.time = game->map.time_base;
    game->map.time += get_time(game);
    game->map.towers[it].arrow = malloc(sizeof(projectile_t));
    game->map.towers[it].arrow->sprite = sfSprite_create();
    sfSprite_setTexture(game->map.towers[it].arrow->sprite,
    game->map.towers[it].t_projectile, sfTrue);
    sfSprite_setRotation(game->map.towers[it].arrow->sprite, angle);
    sfSprite_setPosition(game->map.towers[it].arrow->sprite, pos_tow);
    game->map.towers[it].arrow->step_total =
    game->map.towers[it].attack_speed * 30;
    game->map.towers[it].arrow->last_move = game->map.time;
    game->map.towers[it].in_attack = 1;
    sfRenderWindow_drawSprite(game->win, game->map.towers[it].arrow->sprite,
    NULL);
    set_step(game, it, im, angle);
    game->map.towers[it].arrow->current_step = 0;
}

void handler_arrow(game_t *game)
{
    for (int i = 0; i < 7; i++) {
        if ((game->map.towers[i].type == ARCHER_1 ||
        game->map.towers[i].type == ARCHER_2) &&
        game->map.towers[i].in_attack == 1) {
            move_arrow(game, i);
        }
    }
}

void destroy_arrow(game_t *game, int it)
{
    sfSprite_destroy(game->map.towers[it].arrow->sprite);
    free(game->map.towers[it].arrow);
}