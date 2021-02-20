/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** manage paralax
*/

#include "include/my.h"

void move_par(sfRenderWindow *win, object *obj)
{
    sfVector2f offset;
    sfVector2f pos;

    pos.x = 795;
    pos.y = 0;
    offset.x = obj->move.x;
    offset.y = obj->move.y;
    if (sfSprite_getPosition(obj->sprite).x <= -797)
        sfSprite_setPosition(obj->sprite, pos);
    sfSprite_move(obj->sprite, offset);
}

void reset_paralax(list *l_a)
{
    sfVector2f pos = {0, 0};
    sfVector2f pos_2 = {-799, 0};

    sfSprite_setPosition(l_a->par->b_1->sprite, pos);
    sfSprite_setPosition(l_a->par->b_1_2->sprite, pos_2);
    sfSprite_setPosition(l_a->par->b_2->sprite, pos);
    sfSprite_setPosition(l_a->par->b_2_2->sprite, pos_2);
    sfSprite_setPosition(l_a->par->b_3->sprite, pos);
    sfSprite_setPosition(l_a->par->b_3_2->sprite, pos_2);
    sfSprite_setPosition(l_a->par->b_4->sprite, pos);
    sfSprite_setPosition(l_a->par->b_4_2->sprite, pos_2);
    sfSprite_setPosition(l_a->par->b_5->sprite, pos);
    sfSprite_setPosition(l_a->par->b_5_2->sprite, pos_2);
    sfSprite_setPosition(l_a->par->b_6->sprite, pos);
    sfSprite_setPosition(l_a->par->b_6_2->sprite, pos_2);
}