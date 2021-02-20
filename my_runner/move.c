/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** manage movement
*/

#include "include/my.h"

int manage_move(list *l_a, sfEvent event)
{
    sfVector2f pos = {sfSprite_getPosition(l_a->girl->sprite).x, 376};
    sfVector2f scale = {0.09, 0.09};

    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
        right_move(l_a, event);
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
        left_move(l_a, event);
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
        reduce_move(l_a, event);
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
        if (sfSprite_getScale(l_a->girl->sprite).x <= 0.065) {
            sfSprite_setPosition(l_a->girl->sprite, pos);
            sfSprite_setScale(l_a->girl->sprite, scale);
            return (0);
        }
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
        jump(l_a, event);
}

int reduce_move(list *l_a, sfEvent event)
{
    sfVector2f size;
    sfVector2f pos = {sfSprite_getPosition(l_a->girl->sprite).x, 410};

    size.x = 0.065;
    size.y = 0.065;
    sfSprite_setScale(l_a->girl->sprite, size);
    sfSprite_setPosition(l_a->girl->sprite, pos);
}

int right_move(list *l_a, sfEvent event)
{
    sfVector2f offset = {5, 0};
    sfVector2f pos = sfSprite_getPosition(l_a->girl->sprite);
    sfVector2u siz = sfTexture_getSize(l_a->girl->texture);

    if (pos.x + (siz.x / 4 * sfSprite_getScale(l_a->girl->sprite).x) < 780)
        sfSprite_move(l_a->girl->sprite, offset);
    return (0);
}

int left_move(list *l_a, sfEvent event)
{
    sfVector2f offset = {-8, 0};
    sfVector2f pos = sfSprite_getPosition(l_a->girl->sprite);

    if (pos.x > 10)
        sfSprite_move(l_a->girl->sprite, offset);
    return (0);
}