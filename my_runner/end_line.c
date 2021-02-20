/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** end line
*/

#include "include/my.h"

void insert_end_line(list *l_a, int x, int y)
{
    obs *obj = malloc(sizeof(obs));
    sfVector2f size = {0.12, 0.12};
    sfVector2f pos = {600 + (y * 50), 365};
    sfVector2f move_c = l_a->par->b_1->move;

    obj->type = 1;
    obj->pos = pos;
    obj->move = move_c;
    obj->texture = sfTexture_createFromFile("image/cotton_candy.png", NULL);
    sfTexture_setSmooth(obj->texture, sfTrue);
    obj->sprite = sfSprite_create();
    sfSprite_setScale(obj->sprite, size);
    sfSprite_setPosition(obj->sprite, pos);
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    l_a->list_enemy->end = obj;
}

int check_end_line(list *l_a)
{
    sfVector2f pos_end = sfSprite_getPosition(l_a->list_enemy->end->sprite);
    sfVector2f pos_girl = sfSprite_getPosition(l_a->girl->sprite);

    if (pos_girl.x >= pos_end.x)
        return (1);
    return (0);
}