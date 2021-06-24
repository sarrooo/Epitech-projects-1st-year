/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init fast monster
*/

#include "include/defender.h"

void init_sprite_fast(monster_t *monster, monster_info info)
{
    char path[] = "asset/character/fast.png";

    monster[info.index].sprite = sfSprite_create();
    monster[info.index].texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(monster[info.index].sprite,
    monster[info.index].texture, sfTrue);
    sfSprite_setTextureRect(monster[info.index].sprite,
    monster[info.index].rect);
    sfSprite_setScale(monster[info.index].sprite, (sfVector2f){0.25, 0.25});
    sfSprite_setPosition(monster[info.index].sprite, info.spaw_point);
}

void init_monster_fast(game_t *main_s, monster_info info, monster_t *monster)
{
    info.spaw_point = (sfVector2f){1750, info.spaw_point.y};
    monster[info.index].rect = (sfIntRect){0, 0, 173, 193};
    monster[info.index].health_original = 90;
    monster[info.index].health = 90;
    monster[info.index].damage= 2;
    monster[info.index].speed = 6.0;
    monster[info.index].reward = 5;
    monster[info.index].spawn_point = info.spaw_point;
    monster[info.index].index_point = 0;
    monster[info.index].if_dead = 0;
    monster[info.index].nb_point = 26;
    monster[info.index].point_map = init_point_map1_fast(26,
    monster[info.index].speed);
    monster[info.index].speed_max = 6.0;
    monster[info.index].last_move = 0;
    init_sprite_fast(monster, info);
    monster[info.index].offset_bar = 5;
    monster[info.index].electrise = -1;
    info.scale = (sfVector2f){0.08, 0.08};
    init_bar_healt(main_s, monster, info);
}