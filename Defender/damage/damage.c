/*
** EPITECH PROJECT, 2021
** defender
** File description:
** damage
*/

#include "../include/defender.h"

void apply_damage_spell_fire(game_t *game, int i)
{
    sfVector2f pos =
    sfSprite_getPosition(game->map.monster_wave->monster[i].sprite);
    sfVector2f center =
    sfSprite_getPosition(game->map.fireball.sprite_spell);
    sfIntRect rect = sfSprite_getTextureRect(game->map.fireball.sprite_spell);
    float x_square = ((pos.x - (center.x + 50)) * (pos.x - (center.x + 50)));
    float y_square = ((pos.y - (center.y + 250)) * (pos.y - (center.y + 250)));

    if (game->map.fireball.animation == 1 && x_square + y_square <= 10000
    && rect.left > 1200) {
        game->map.monster_wave->monster[i].health -= 30;
        sfSprite_setColor(game->map.monster_wave->monster[i].sprite,
        sfRed);
    }
}

void apply_damage_spell_freeze(game_t *game, int i)
{
    sfVector2f pos =
    sfSprite_getPosition(game->map.monster_wave->monster[i].sprite);
    sfVector2f center =
    sfSprite_getPosition(game->map.freeze.sprite_spell);
    float x_square = ((pos.x - (center.x + 50)) * (pos.x - (center.x + 50)));
    float y_square = ((pos.y - (center.y + 250)) * (pos.y - (center.y + 250)));

    if (game->map.freeze.animation == 1 && x_square + y_square <= 10000
    && game->map.time > game->map.freeze.last_move + 0.2) {
        game->map.monster_wave->monster[i].speed =
        game->map.monster_wave->monster[i].speed_max / 2.0;
    }
    if (game->map.freeze.animation == 1 && x_square + y_square <= 10000) {
        sfSprite_setColor(game->map.monster_wave->monster[i].sprite,
        sfBlue);
    }
}

int check_tower_can_attack(game_t *game, int it)
{
    sfIntRect rect = sfSprite_getTextureRect(game->map.towers[it].sprite);

    if (game->map.towers[it].in_attack != 1) {
        return (0);
    }
    return (84);
}

int check_if_monster_is_in_range(game_t *game, int it, int im, int type)
{
    sfVector2f pos_mob =
    sfSprite_getPosition(game->map.monster_wave->monster[im].sprite);
    sfVector2f pos_tow = game->map.towers[it].position;
    sfIntRect rect = sfSprite_getTextureRect(game->map.towers[it].sprite);
    float x_square = pow((pos_mob.x - (pos_tow.x + 100)), 2);
    float y_square = pow((pos_mob.y - (pos_tow.y + 100)), 2);

    if (check_tower_can_attack(game, it) == 84)
        return (84);
    if (x_square + y_square <= pow(game->map.towers[it].range, 2)) {
        if (type == 1) {
            calcul_angle(game, im, it);
            rect.left = 250;
            sfSprite_setTextureRect(game->map.towers[it].sprite, rect);
        }
        if (type == 2) {
            apply_thunder(game, it, im);
            return (0);
        }
    }
    check_if_monster_is_in_range2(game, it, im);
}

void apply_damage(game_t *game, int i)
{
    if (game->map.fireball.animation == 1 &&
    game->map.time > game->map.fireball.last_move + 0.2)
        apply_damage_spell_fire(game, i);
    else
        sfSprite_setColor(game->map.monster_wave->monster[i].sprite,
        sfWhite);
    game->map.monster_wave->monster[i].speed =
    game->map.monster_wave->monster[i].speed_max;
    apply_damage_spell_freeze(game, i);
    for (int j = 0; j < 7; j++) {
        if (game->map.towers[j].type == ARCHER_1 ||
        game->map.towers[j].type == ARCHER_2)
            check_if_monster_is_in_range(game, j, i, 1);
        if (game->map.towers[j].type == MAGICIAN_1 ||
        game->map.towers[j].type == MAGICIAN_2)
            check_if_monster_is_in_range(game, j, i, 2);
    }
}