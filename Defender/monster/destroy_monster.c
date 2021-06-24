/*
** EPITECH PROJECT, 2021
** my_defeender
** File description:
** destroy monster
*/

#include "include/defender.h"

void destroy_monster(monster_t *monster, int index)
{
    sfSprite_destroy(monster[index].sprite);
    sfTexture_destroy(monster[index].texture);
    free(monster[index].point_map);
    destroy_object(monster[index].bar);
    destroy_object(monster[index].bar_bg);
}