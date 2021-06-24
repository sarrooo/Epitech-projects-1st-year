/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init towers
*/

#include "../include/defender.h"

void init_archery_11(game_t *game, int index, sfVector2f position)
{
    game->map.data->points_gold -= 100;
    game->map.towers[index].type = ARCHER_1;
    game->map.towers[index].damage = game->map.stats->archery1.damage;
    game->map.towers[index].attack_speed =
    game->map.stats->archery1.attack_speed;
    game->map.towers[index].range = game->map.stats->archery1.range;
    game->map.towers[index].sprite = sfSprite_create();
    game->map.towers[index].texture =
    sfTexture_createFromFile("./asset/archery_lvl1.png", NULL);
}

void init_archery_22(game_t *game, int index, sfVector2f position)
{
    game->map.data->points_gold -= 250;
    game->map.towers[index].type = ARCHER_2;
    game->map.towers[index].damage = game->map.stats->archery2.damage;
    game->map.towers[index].attack_speed =
    game->map.stats->archery2.attack_speed;
    game->map.towers[index].range = game->map.stats->archery2.range;
    game->map.towers[index].sprite = sfSprite_create();
    game->map.towers[index].texture =
    sfTexture_createFromFile("./asset/archery_lvl2.png", NULL);
}

void init_magic_11(game_t *game, int index, sfVector2f position)
{
    game->map.data->points_gold -= 100;
    game->map.towers[index].type = MAGICIAN_1;
    game->map.towers[index].damage = game->map.stats->magic1.damage;
    game->map.towers[index].attack_speed =
    game->map.stats->magic1.attack_speed;
    game->map.towers[index].range = game->map.stats->magic1.range;
    game->map.towers[index].sprite = sfSprite_create();
    game->map.towers[index].texture =
    sfTexture_createFromFile("./asset/magic_lv1.png", NULL);
}

void init_magic_22(game_t *game, int index, sfVector2f position)
{
    game->map.data->points_gold -= 250;
    game->map.towers[index].type = MAGICIAN_2;
    game->map.towers[index].damage = game->map.stats->magic2.damage;
    game->map.towers[index].attack_speed =
    game->map.stats->magic2.attack_speed;
    game->map.towers[index].range = game->map.stats->magic2.range;
    game->map.towers[index].sprite = sfSprite_create();
    game->map.towers[index].texture =
    sfTexture_createFromFile("./asset/magic_lv2.png", NULL);
}