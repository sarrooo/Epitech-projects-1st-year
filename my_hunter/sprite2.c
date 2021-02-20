/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** sprite 2
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <time.h>
#include "include/my.h"
#include <stdio.h>

sfSprite *spaw_p(int *b, sfSprite *pr, sfRenderWindow *win, int *flow)
{
    sfIntRect *rect = rect_sprite(343, 300);

    if (b[0] == 2) {
        pr = sprite_sheet_parrot2(win, rect);
        flow[0] = flow[0] * -1;
    }
    else
        pr = sprite_sheet_parrot(win, rect);
    return (pr);
}

sfSprite *play(sfRenderWindow *win)
{
    sfTexture *texture = sfTexture_createFromFile("image/play.png", NULL);
    sfSprite *button = sfSprite_create();
    sfVector2f pos = {(1400 / 2) - (545 / 2), (800 / 2) - (166 / 2)};
    sfVector2f size;

    size.x = (float)sfTexture_getSize(texture).x / 545;
    size.y = (float)sfTexture_getSize(texture).y / 166;
    sfSprite_setScale(button, size);
    sfTexture_setSmooth(texture, sfTrue);
    sfSprite_setPosition(button, pos);
    sfSprite_setTexture(button, texture, sfTrue);
    return (button);
}

sfSprite *replay(sfRenderWindow *win)
{
    sfTexture *texture = sfTexture_createFromFile("image/replay.png", NULL);
    sfSprite *button = sfSprite_create();
    sfVector2f pos = {(1400 / 2) - (250 / 2) - 100, (800 / 2) - (250 / 2)};
    sfVector2f size;

    size.x = 0.5;
    size.y = 0.5;
    sfSprite_setScale(button, size);
    sfTexture_setSmooth(texture, sfTrue);
    sfSprite_setPosition(button, pos);
    sfSprite_setTexture(button, texture, sfTrue);
    return (button);
}

sfSprite *quit(sfRenderWindow *win)
{
    sfTexture *texture = sfTexture_createFromFile("image/quit.png", NULL);
    sfSprite *button = sfSprite_create();
    sfVector2f pos = {(1400 / 2) - (250 / 2) + 100, (800 / 2) - (250 / 2)};
    sfVector2f size;

    size.x = 2.5;
    size.y = 2.5;
    sfSprite_setScale(button, size);
    sfTexture_setSmooth(texture, sfTrue);
    sfSprite_setPosition(button, pos);
    sfSprite_setTexture(button, texture, sfTrue);
    return (button);
}
