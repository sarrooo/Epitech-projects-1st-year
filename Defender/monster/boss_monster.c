/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init boss monster
*/

#include "include/defender.h"

void init_sprite_boss(monster_t *monster, monster_info info)
{
    char path[] = "asset/character/boss.png";

    monster[info.index].sprite = sfSprite_create();
    monster[info.index].texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(monster[info.index].sprite,
    monster[info.index].texture, sfTrue);
    sfSprite_setTextureRect(monster[info.index].sprite,
    monster[info.index].rect);
    sfSprite_setScale(monster[info.index].sprite, (sfVector2f){0.27, 0.27});
    sfSprite_setPosition(monster[info.index].sprite, info.spaw_point);
}

void init_monster_boss(game_t *main_s, monster_info info, monster_t *monster)
{
    info.spaw_point = (sfVector2f){1700, info.spaw_point.y};
    monster[info.index].rect = (sfIntRect){0, 0, 483, 470};
    monster[info.index].health_original = 2250;
    monster[info.index].health = 2250;
    monster[info.index].damage= 15;
    monster[info.index].speed = 1.5;
    monster[info.index].reward = 100;
    monster[info.index].spawn_point = info.spaw_point;
    monster[info.index].index_point = 0;
    monster[info.index].if_dead = 0;
    monster[info.index].nb_point = 60;
    monster[info.index].point_map = init_point_map1_boss(60,
    monster[info.index].speed);
    monster[info.index].last_move = 0;
    monster[info.index].speed_max = 1.5;
    monster[info.index].electrise = -1;
    init_sprite_boss(monster, info);
    monster[info.index].offset_bar = 20;
    info.scale = (sfVector2f){0.2, 0.2};
    init_bar_healt(main_s, monster, info);
}