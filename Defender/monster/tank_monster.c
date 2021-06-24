/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init tank monster
*/

#include "include/defender.h"

void init_sprite_tank(monster_t *monster, monster_info info)
{
    char path[] = "asset/character/tank.png";

    monster[info.index].sprite = sfSprite_create();
    monster[info.index].texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(monster[info.index].sprite,
    monster[info.index].texture, sfTrue);
    sfSprite_setTextureRect(monster[info.index].sprite,
    monster[info.index].rect);
    sfSprite_setScale(monster[info.index].sprite, (sfVector2f){0.33, 0.33});
    sfSprite_setPosition(monster[info.index].sprite, info.spaw_point);
}

void init_monster_tank(game_t *main_s, monster_info info, monster_t *monster)
{
    info.spaw_point = (sfVector2f){1730, info.spaw_point.y};
    monster[info.index].rect = (sfIntRect){0, 0, 238, 289};
    monster[info.index].health_original = 450;
    monster[info.index].health = 450;
    monster[info.index].damage= 8;
    monster[info.index].speed = 2.0;
    monster[info.index].reward = 30;
    monster[info.index].spawn_point = info.spaw_point;
    monster[info.index].index_point = 0;
    monster[info.index].if_dead = 0;
    monster[info.index].nb_point = 60;
    monster[info.index].point_map = init_point_map1_tank(60,
    monster[info.index].speed);
    monster[info.index].speed_max = 2.0;
    monster[info.index].last_move = 0;
    monster[info.index].electrise = -1;
    init_sprite_tank(monster, info);
    monster[info.index].offset_bar = 5;
    info.scale = (sfVector2f){0.08, 0.08};
    init_bar_healt(main_s, monster, info);
}