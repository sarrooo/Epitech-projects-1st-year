/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** Manage sprite sheet
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Config.h>
#include <SFML/Audio.h>
#include "include/my.h"
#include <time.h>

sfSprite *sprite_sheet_parrot(sfRenderWindow *window, sfIntRect *rect)
{
    sfTexture *texture = sfTexture_createFromFile("image/parrot_m.png", NULL);
    sfSprite *parrot = sfSprite_create();
    int size_win_x = sfRenderWindow_getSize(window).x;
    int size_win_y = sfRenderWindow_getSize(window).y;
    sfVector2f size;
    int b;
    sfVector2f pos = {0, 0};

    srand(time(NULL));
    b = rand() % (800 - (800 / 2)) + 20;
    pos.y = b;
    sfTexture_setSmooth(texture, sfTrue);
    size.x = (float)sfTexture_getSize(texture).x / 1400 / 1.5;
    size.y = (float)sfTexture_getSize(texture).y / 800 / 1.5;
    sfSprite_setScale(parrot, size);
    sfSprite_setPosition(parrot, pos);
    sfSprite_setTexture(parrot, texture, sfTrue);
    return (parrot);
}

sfSprite *sprite_sheet_parrot2(sfRenderWindow *window, sfIntRect *rect)
{
    sfTexture *texture = sfTexture_createFromFile("image/parrot_r.png", NULL);
    sfSprite *parrot = sfSprite_create();
    int size_win_x = sfRenderWindow_getSize(window).x;
    int size_win_y = sfRenderWindow_getSize(window).y;
    sfVector2f size;
    int b;
    sfVector2f pos = {1400, 0};

    srand(time(NULL));
    sfTexture_setSmooth(texture, sfTrue);
    size.x = (float)sfTexture_getSize(texture).x / 1400 / 1.5;
    size.y = (float)sfTexture_getSize(texture).y / 800 / 1.5;
    b = rand() % (800 - (800 / 2)) + 20;
    pos.y = b;
    sfSprite_setScale(parrot, size);
    sfSprite_setPosition(parrot, pos);
    sfSprite_setTexture(parrot, texture, sfTrue);
    return (parrot);
}

sfIntRect *move_rect(sfIntRect *rect, int *max, sfSprite *p, sfRenderWindow *w)
{
    int s_win_x = sfRenderWindow_getSize(w).x;
    int s_win_y = sfRenderWindow_getSize(w).y;
    sfVector2f s;

    rect->left = rect->left + max[0];
    rect->width = rect->width;
    rect->height = rect->height;
    s.x = (float)sfTexture_getSize(sfSprite_getTexture(p)).x / 1400 / 1.5;
    s.y = (float)sfTexture_getSize(sfSprite_getTexture(p)).y / 800 / 1.5;
    sfSprite_setScale(p, s);
    if (rect->left == max[1]) {
        rect->left = 0;
        rect->top = rect->top + 300;
        if (rect->top >= max[2]) {
            rect->left = 0;
            rect->top = 0;
            return (rect);
        }
    }
    return (rect);
}

sfIntRect *rect_sprite(int width, int height)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = 0;
    rect->left = 0;
    rect->width = width;
    rect->height = height;
    return (rect);
}

void count_seconds(sfRenderWindow *window, sfIntRect *rect, int i, sfSprite *p)
{
    sfClock *clock;
    sfTime time;
    float seconds;

    clock = sfClock_create();
    while (1) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.05895) {
            sprite_sheet_main(window, rect, i, p);
            break;
        }
    }
    sfClock_destroy(clock);
}
