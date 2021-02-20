/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** button
*/

#include "include/my.h"

sfSprite *draw_reload(sfRenderWindow *win)
{
    sfTexture *texture = sfTexture_createFromFile("button/reload.png", NULL);
    sfSprite *button = sfSprite_create();
    sfVector2f pos = {370, 200};
    sfVector2f size;

    size.x = 0.4;
    size.y = 0.4;
    sfSprite_setScale(button, size);
    sfTexture_setSmooth(texture, sfTrue);
    sfSprite_setPosition(button, pos);
    sfSprite_setTexture(button, texture, sfTrue);
    return (button);
}