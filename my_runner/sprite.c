/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** manage sprite
*/

#include "include/my.h"

sfIntRect *rect_sprite(int width, int height)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = 0;
    rect->left = 0;
    rect->width = width;
    rect->height = height;
    return (rect);
}

sfIntRect *rect_jump(int width, int height)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = 1250;
    rect->left = 0;
    rect->width = width;
    rect->height = height;
    return (rect);
}

void count_seconds(sfRenderWindow *window)
{
    sfClock *clock;
    sfTime time;
    float seconds;

    clock = sfClock_create();
    while (1) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.060) {
            break;
        }
    }
    sfClock_destroy(clock);
}

void count_seconds_jump(sfRenderWindow *window)
{
    sfClock *clock;
    sfTime time;
    float seconds;

    clock = sfClock_create();
    while (1) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.25) {
            break;
        }
    }
    sfClock_destroy(clock);
}