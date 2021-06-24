/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** check hitbox for rect button
*/

#include "include/defender.h"

int is_rect_hover(game_t *main_s, sfRectangleShape *button, sfVector2f clic)
{
    sfVector2f pos = sfRectangleShape_getPosition(button);
    sfVector2f size = sfRectangleShape_getSize(button);

    if (clic.x <= pos.x + size.x && clic.x >= pos.x)
        if (clic.y <= pos.y + size.y && clic.y >= pos.y) {
            sfRectangleShape_setFillColor(button, sfYellow);
            return (1);
        }
    sfRectangleShape_setFillColor(button, sfWhite);
    return (0);
}

int is_rect_clic(game_t *main_s, sfRectangleShape *button, sfVector2f clic)
{
    sfVector2f pos = sfRectangleShape_getPosition(button);
    sfVector2f size = sfRectangleShape_getSize(button);

    if (clic.x <= pos.x + size.x && clic.x >= pos.x)
        if (clic.y <= pos.y + size.y && clic.y >= pos.y) {
            return (1);
        }
    return (0);
}