/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** handler for monster wave
*/

#include "include/defender.h"

void monster_limit_y(monster_t *monster, int index)
{
    int index_point = monster[index].index_point;
    sfVector2f pos = sfSprite_getPosition(monster[index].sprite);
    sfVector2f pos_max = monster[index].point_map[index_point].max_point;
    sfVector2f move = monster[index].point_map[index_point].move;

    if (move.y < 0 && pos.y <= pos_max.y) {
        monster[index].index_point++;
        if (monster[index].index_point != monster[index].nb_point)
            set_orientation_monster(monster, index);
    }
    else if (move.y > 0 && pos.y >= pos_max.y) {
        monster[index].index_point++;
        if (monster[index].index_point != monster[index].nb_point)
            set_orientation_monster(monster, index);
    }
}

void monster_limit_x(monster_t *monster, int index)
{
    int index_point = monster[index].index_point;
    sfVector2f pos = sfSprite_getPosition(monster[index].sprite);
    sfVector2f pos_max = monster[index].point_map[index_point].max_point;
    sfVector2f move = monster[index].point_map[index_point].move;

    if (move.x < 0 && pos.x <= pos_max.x) {
        monster[index].index_point++;
        if (monster[index].index_point != monster[index].nb_point)
            set_orientation_monster(monster, index);
    }
    else if (move.x > 0 && pos.x >= pos_max.x) {
        set_orientation_monster(monster, index);
        if (monster[index].index_point != monster[index].nb_point)
            monster[index].index_point++;
    }
}

void move_monster(game_t *main_s, monster_t *monster, int index)
{
    int index_point = monster[index].index_point;
    sfVector2f move = monster[index].point_map[index_point].move;

    if (move.x < 0)
        move.x = monster[index].speed * -1;
    if (move.x > 0)
        move.x = monster[index].speed;
    if (move.y < 0)
        move.y = monster[index].speed * -1;
    if (move.y > 0)
        move.y = monster[index].speed;
    if (move.x == 0.0)
        monster_limit_y(monster, index);
    else
        monster_limit_x(monster, index);
    sfSprite_move(monster[index].sprite, move);
}

void animation_monster(game_t *main_s, monster_t *monster, int index)
{
    sfIntRect rect = monster[index].rect;
    sfIntRect new_rect;
    sfVector2u size_texture = sfTexture_getSize(monster[index].texture);

    new_rect.left = rect.left + rect.width;
    new_rect.top = rect.top;
    new_rect.width = rect.width;
    new_rect.height = rect.height;
    if (new_rect.left >= size_texture.x - 2) {
        new_rect.left = 0;
    }
    monster[index].rect = new_rect;
    sfSprite_setTextureRect(monster[index].sprite, new_rect);
}