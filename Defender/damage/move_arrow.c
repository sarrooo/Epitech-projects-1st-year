/*
** EPITECH PROJECT, 2021
** defender
** File description:
** move_arrow
*/

#include "../include/defender.h"

void damage_effect_arrow(game_t *game, int it, int i)
{
    if (game->map.towers[it].arrow->current_step >=
    game->map.towers[it].arrow->step_total) {
        game->map.towers[it].in_attack = 0;
        game->map.monster_wave->monster[i].health -=
        game->map.towers[it].damage;
        sfSprite_setColor(game->map.monster_wave->monster[i].sprite, sfRed);
        if (game->map.monster_wave->monster[i].if_dead == 0)
            sfRenderWindow_drawSprite(game->win,
            game->map.monster_wave->monster[i].sprite, NULL);
        destroy_arrow(game, it);
    } else {
        sfRenderWindow_drawSprite(game->win,
        game->map.towers[it].arrow->sprite, NULL);
    }
}

void move_arrow(game_t *game, int it)
{
    sfVector2f pos_arrow =
    sfSprite_getPosition(game->map.towers[it].arrow->sprite);
    game->map.time = game->map.time_base;
    game->map.time += get_time(game);
    int i = game->map.towers[it].arrow->target;

    if (game->map.time > game->map.towers[it].arrow->last_move + 1 / 30.0) {
        pos_arrow.x -= game->map.towers[it].arrow->step_x;
        pos_arrow.y -= game->map.towers[it].arrow->step_y;
        game->map.towers[it].arrow->current_step += 1;
        game->map.towers[it].arrow->last_move = game->map.time;
        sfSprite_setPosition(game->map.towers[it].arrow->sprite, pos_arrow);
    }
    if (game->map.towers[it].arrow->current_step >=
    game->map.towers[it].arrow->step_total / 2.0) {
        sfSprite_setTextureRect(game->map.towers[it].sprite,
        (sfIntRect){0, 0, 250, 250});
    }
    damage_effect_arrow(game, it, i);
}