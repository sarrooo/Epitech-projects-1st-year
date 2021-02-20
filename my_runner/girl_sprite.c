/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** manage girl sprite
*/

#include "include/my.h"

object *create_girl(sfRenderWindow *win)
{
    object *obj = malloc(sizeof(object));
    sfVector2f size;
    sfVector2f pos = {15, 376};

    obj->texture = sfTexture_createFromFile("image/girl.png", NULL);
    sfTexture_setSmooth(obj->texture, sfTrue);
    obj->sprite = sfSprite_create();
    size.x = 0.09;
    size.y = 0.09;
    sfSprite_setScale(obj->sprite, size);
    sfSprite_setPosition(obj->sprite, pos);
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    return (obj);
}

void move_girl(sfRenderWindow *win, object *girl, sfIntRect *rect, list *l_a)
{
    sfVector2f s;

    rect->left = rect->left + 1250;
    rect->width = rect->width;
    rect->height = rect->height;
    if (rect->left >= 5000) {
        rect->left = 0;
        if (rect->top >= 2500) {
            rect->left = 0;
            rect->top = 0;
        }
        rect->top = 2500;
    }
    sfSprite_setTextureRect(girl->sprite, *rect);
    sfRenderWindow_drawSprite(win, girl->sprite, NULL);
}