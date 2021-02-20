/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** manage sprite bonus
*/

#include "include/my.h"

obs *create_bonus(list *l_a)
{
    obs *obj = malloc(sizeof(obs));
    sfVector2f size = {0.1, 0.1};
    sfVector2f pos = {0, 0};
    sfVector2f move_c = l_a->par->b_1->move;

    obj->type = 4;
    obj->texture = sfTexture_createFromFile("image/candy.png", NULL);
    obj->sprite = sfSprite_create();
    obj->move = move_c;
    sfTexture_setSmooth(obj->texture, sfTrue);
    sfSprite_setScale(obj->sprite, size);
    sfSprite_setPosition(obj->sprite, pos);
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    return (obj);
}

obs *create_malus(list *l_a)
{
    obs *obj = malloc(sizeof(obs));
    sfVector2f size = {0.1, 0.1};
    sfVector2f pos = {0, 0};
    sfVector2f move_c = l_a->par->b_1->move;

    obj->type = 5;
    obj->texture = sfTexture_createFromFile("image/vegetable.png", NULL);
    obj->sprite = sfSprite_create();
    obj->move = move_c;
    sfTexture_setSmooth(obj->texture, sfTrue);
    sfSprite_setScale(obj->sprite, size);
    sfSprite_setPosition(obj->sprite, pos);
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    return (obj);
}