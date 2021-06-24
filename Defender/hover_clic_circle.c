/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** check hitbox for circle button
*/

#include "include/defender.h"

int is_circle_hover(game_t *main_s, sfCircleShape *button, sfVector2f clic)
{
    sfFloatRect size = sfCircleShape_getLocalBounds(button);
    sfVector2f pos = sfCircleShape_getPosition(button);
    int radius = sfCircleShape_getRadius(button);
    float x_square = (clic.x - (pos.x + radius)) * (clic.x - (pos.x + radius));
    float y_square = (clic.y - (pos.y + radius)) * (clic.y - (pos.y + radius));

    if (x_square + y_square <= radius * radius) {
        sfCircleShape_setFillColor(button, sfYellow);
        return (1);
    }
    sfCircleShape_setFillColor(button, sfWhite);
    return (0);
}

int is_circle_clic(game_t *main_s, sfCircleShape *button, sfVector2f clic)
{
    sfFloatRect size = sfCircleShape_getLocalBounds(button);
    sfVector2f pos = sfCircleShape_getPosition(button);
    int radius = sfCircleShape_getRadius(button);
    float x_square = (clic.x - (pos.x + radius)) * (clic.x - (pos.x + radius));
    float y_square = (clic.y - (pos.y + radius)) * (clic.y - (pos.y + radius));

    if (x_square + y_square <= radius * radius) {
        return (1);
    }
    return (0);
}