/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** move obstacles
*/

#include "include/my.h"

void move_cat(obs *obstacle, sfRenderWindow *win)
{
    obstacle->rect->left = 400;
    obstacle->rect->top = obstacle->rect->top + 105;
    if (obstacle->rect->top >= 418)
        obstacle->rect->top = 0;
    sfSprite_setTextureRect(obstacle->sprite, *obstacle->rect);
}

void move_bird(obs *obstacle, sfRenderWindow *win)
{
    obstacle->rect->left = obstacle->rect->left + 360;
    if (obstacle->rect->left >= 1080) {
        obstacle->rect->left = 0;
        obstacle->rect->top = obstacle->rect->top + 360;
        if (obstacle->rect->top >= 1080) {
            obstacle->rect->left = 0;
            obstacle->rect->top = 0;
        }
    }
    sfSprite_setTextureRect(obstacle->sprite, *obstacle->rect);
}

void move_dodo(obs *obstacle, sfRenderWindow *win)
{
    obstacle->rect->top = 0;
    obstacle->rect->left = obstacle->rect->left + 109;
    if (obstacle->rect->left >= 430)
        obstacle->rect->left = 0;
    sfSprite_setTextureRect(obstacle->sprite, *obstacle->rect);
}