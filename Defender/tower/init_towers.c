/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init towers
*/

#include "../include/defender.h"

void init_archery_1(game_t *game, int index, sfVector2f position)
{
    init_archery_11(game, index, position);
    game->map.towers[index].rect = (sfIntRect) {0, 0 , 250, 250};
    sfSprite_setTexture(game->map.towers[index].sprite,
    game->map.towers[index].texture, sfTrue);
    sfSprite_setTextureRect(game->map.towers[index].sprite,
    game->map.towers[index].rect);
    game->map.towers[index].position = position;
    sfSprite_setPosition(game->map.towers[index].sprite, position);
    sfSound_setVolume(game->map.build.sound, game->volume);
    sfSound_play(game->map.build.sound);
    game->map.towers[index].t_projectile =
    sfTexture_createFromFile("./asset/light_arrow.png", NULL);
    game->map.towers[index].in_attack = 0;
}

void init_archery_2(game_t *game, int index, sfVector2f position)
{
    init_archery_22(game, index, position);
    game->map.towers[index].rect = (sfIntRect) {0, 0 , 250, 250};
    sfSprite_setTexture(game->map.towers[index].sprite,
    game->map.towers[index].texture, sfTrue);
    sfSprite_setTextureRect(game->map.towers[index].sprite,
    game->map.towers[index].rect);
    game->map.towers[index].position = position;
    sfSprite_setPosition(game->map.towers[index].sprite, position);
    sfSound_setVolume(game->map.build.sound, game->volume);
    sfSound_play(game->map.build.sound);
    game->map.towers[index].t_projectile =
    sfTexture_createFromFile("./asset/heavy_arrow.png", NULL);
    game->map.towers[index].in_attack = 0;
}

void init_magic_1(game_t *game, int index, sfVector2f position)
{
    init_magic_11(game, index, position);
    game->map.towers[index].rect = (sfIntRect) {0, 0 , 200, 220};
    sfSprite_setTexture(game->map.towers[index].sprite,
    game->map.towers[index].texture, sfTrue);
    sfSprite_setTextureRect(game->map.towers[index].sprite,
    game->map.towers[index].rect);
    game->map.towers[index].position = position;
    sfSprite_setPosition(game->map.towers[index].sprite, position);
    sfSound_setVolume(game->map.build.sound, game->volume);
    sfSound_play(game->map.build.sound);
    game->map.towers[index].in_attack = 0;
    game->map.towers[index].t_projectile =
    sfTexture_createFromFile("./asset/weak_flash.png", NULL);
    game->map.towers[index].in_attack = 0;
    game->map.towers[index].timer = 0;
    init_thunder(game, index);
}

void init_magic_2(game_t *game, int index, sfVector2f position)
{
    init_magic_22(game, index, position);
    game->map.towers[index].rect = (sfIntRect) {0, 0 , 200, 220};
    sfSprite_setTexture(game->map.towers[index].sprite,
    game->map.towers[index].texture, sfTrue);
    sfSprite_setTextureRect(game->map.towers[index].sprite,
    game->map.towers[index].rect);
    game->map.towers[index].position = position;
    sfSprite_setPosition(game->map.towers[index].sprite, position);
    sfSound_setVolume(game->map.build.sound, game->volume);
    sfSound_play(game->map.build.sound);
    game->map.towers[index].t_projectile =
    sfTexture_createFromFile("./asset/strong_flash.png", NULL);
    init_thunder(game, index);
    game->map.towers[index].timer = 0;
    game->map.towers[index].in_attack = 0;
}

void destroy_tower(game_t *game, int index)
{
    sfSprite_destroy(game->map.towers[index].sprite);
    sfTexture_destroy(game->map.towers[index].texture);
    sfTexture_destroy(game->map.towers[index].t_projectile);
    if (game->map.towers[index].type == MAGICIAN_1 ||
    game->map.towers[index].type == MAGICIAN_2)
        destroy_thunder(game, index);
    game->map.towers[index].type = 0;
}