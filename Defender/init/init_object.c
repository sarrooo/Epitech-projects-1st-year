/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** manage UI object
*/

#include "include/defender.h"

void init_object(game_t *main_s, info_t info, object_t *obj)
{
    sfTexture *texture = sfTexture_createFromFile(info.path, NULL);
    sfSprite *sprite = sfSprite_create();

    sfTexture_setSmooth(texture, sfTrue);
    sfSprite_setPosition(sprite, info.pos);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, info.scale);
    obj->texture = texture;
    obj->sprite = sprite;
}