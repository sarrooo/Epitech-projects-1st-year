/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** draw button
*/

#include "include/my.h"

sfSprite *draw_play(sfRenderWindow *win)
{
    sfTexture *texture = sfTexture_createFromFile("button/play_2.png", NULL);
    sfSprite *button = sfSprite_create();
    int x = 5000;
    float s = 0.06;
    sfVector2f pos = {(800 / 2) - (x * s / 2), (600 / 2) - (2500 * s / 2)};
    sfVector2f size;
    sfIntRect rect = {0, 0, 5000, 2500};

    size.x = 0.06;
    size.y = 0.06;
    sfSprite_setScale(button, size);
    sfTexture_setSmooth(texture, sfTrue);
    sfSprite_setPosition(button, pos);
    sfSprite_setTexture(button, texture, sfTrue);
    sfSprite_setTextureRect(button, rect);
    return (button);
}

sfSprite *draw_music(sfRenderWindow *win, sfMusic *music)
{
    sfTexture *texture;
    sfSprite *button = sfSprite_create();
    sfVector2f pos = {10, 10};
    sfVector2f size;

    if (sfMusic_getStatus(music) == sfPlaying) {
        texture = sfTexture_createFromFile("button/sound.png", NULL);
    }
    else {
        texture = sfTexture_createFromFile("button/sound_off.png", NULL);
    }
    size.x = 0.4;
    size.y = 0.4;
    sfSprite_setScale(button, size);
    sfTexture_setSmooth(texture, sfTrue);
    sfSprite_setPosition(button, pos);
    sfSprite_setTexture(button, texture, sfTrue);
    return (button);
}

sfSprite *draw_pause(sfRenderWindow *win)
{
    sfTexture *texture = sfTexture_createFromFile("button/pause.png", NULL);
    sfSprite *button = sfSprite_create();
    sfVector2f pos = {735, 10};
    sfVector2f size;

    size.x = 0.4;
    size.y = 0.4;
    sfSprite_setScale(button, size);
    sfTexture_setSmooth(texture, sfTrue);
    sfSprite_setPosition(button, pos);
    sfSprite_setTexture(button, texture, sfTrue);
    return (button);
}

sfSprite *draw_quit(sfRenderWindow *win)
{
    sfTexture *texture = sfTexture_createFromFile("button/exit.png", NULL);
    sfSprite *button = sfSprite_create();
    sfVector2f pos = {450, 200};
    sfVector2f size;

    size.x = 0.4;
    size.y = 0.4;
    sfSprite_setScale(button, size);
    sfTexture_setSmooth(texture, sfTrue);
    sfSprite_setPosition(button, pos);
    sfSprite_setTexture(button, texture, sfTrue);
    return (button);
}

sfSprite *draw_resume(sfRenderWindow *win)
{
    sfTexture *texture = sfTexture_createFromFile("button/play.png", NULL);
    sfSprite *button = sfSprite_create();
    sfVector2f pos = {285, 200};
    sfVector2f size;

    size.x = 0.4;
    size.y = 0.4;
    sfSprite_setScale(button, size);
    sfTexture_setSmooth(texture, sfTrue);
    sfSprite_setPosition(button, pos);
    sfSprite_setTexture(button, texture, sfTrue);
    return (button);
}