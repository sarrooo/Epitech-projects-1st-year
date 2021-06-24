/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** set orientation of monster
*/

#include "include/defender.h"

void set_orientation_monster(monster_t *monster, int index)
{
    int index_point = monster[index].index_point;
    sfVector2f move = monster[index].point_map[index_point].move;
    sfIntRect rect = monster[index].rect;
    sfIntRect new_rect = rect;

    if (move.x < 0) {
        new_rect.top = rect.height;
        monster[index].rect = new_rect;
        sfSprite_setTextureRect(monster[index].sprite, new_rect);
    }
    if (move.x > 0) {
        new_rect.top = 0;
        monster[index].rect = new_rect;
        sfSprite_setTextureRect(monster[index].sprite, new_rect);
    }
}