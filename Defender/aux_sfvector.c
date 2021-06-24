/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** convert 2x int to sfvector
*/

#include "include/defender.h"

sfVector2f int_to_sfvector2f(int x, int y)
{
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    return (pos);
}

sfIntRect int_to_sfintrect(int left, int top, int width, int height)
{
    sfIntRect rect;

    rect.left = left;
    rect.top = top;
    rect.width = width;
    rect.height = height;
    return (rect);
}