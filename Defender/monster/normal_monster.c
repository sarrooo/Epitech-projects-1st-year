/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init normal monster
*/

#include "include/defender.h"

void init_sprite_normal(monster_t *monster, monster_info info)
{
    char path[] = "asset/character/normal.png";

    monster[info.index].sprite = sfSprite_create();
    monster[info.index].texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(monster[info.index].sprite,
    monster[info.index].texture, sfTrue);
    sfSprite_setTextureRect(monster[info.index].sprite,
    monster[info.index].rect);
    sfSprite_setScale(monster[info.index].sprite, (sfVector2f){0.2, 0.2});
    sfSprite_setPosition(monster[info.index].sprite, info.spaw_point);
}

void init_monster_normal(game_t *main_s, monster_info info, monster_t *monster)
{
    info.spaw_point = (sfVector2f){1750, info.spaw_point.y};
    monster[info.index].rect = (sfIntRect){0, 0, 272, 292};
    monster[info.index].health_original = 220;
    monster[info.index].health = 220;
    monster[info.index].damage= 3;
    monster[info.index].speed = 3.5;
    monster[info.index].reward = 15;
    monster[info.index].spawn_point = info.spaw_point;
    monster[info.index].index_point = 0;
    monster[info.index].if_dead = 0;
    monster[info.index].nb_point = 26;
    monster[info.index].point_map = init_point_map1_normal(26,
    monster[info.index].speed);
    monster[info.index].speed_max = 3.5;
    monster[info.index].last_move = -1;
    init_sprite_normal(monster, info);
    monster[info.index].offset_bar = 5;
    monster[info.index].electrise = 0;
    info.scale = (sfVector2f){0.08, 0.08};
    init_bar_healt(main_s, monster, info);
}