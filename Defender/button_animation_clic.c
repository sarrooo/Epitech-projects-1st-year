/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** animation clic button
*/

#include "include/defender.h"

void animation_rect_none(game_t *main_s, rect_but *but)
{
    sfVector2f scale_2 = {1, 1};

    sfRectangleShape_setScale(but->button, scale_2);
    sfRectangleShape_setPosition(but->button, but->original_pos);
}

void animation_rect_clic(game_t *main_s, rect_but but)
{
    sfVector2f size = sfRectangleShape_getSize(but.button);
    sfVector2f pos = sfRectangleShape_getPosition(but.button);
    sfVector2f new_size;
    sfVector2f new_pos;
    sfVector2f scale = {0.7, 0.7};
    sfVector2f scale_2 = {1, 1};

    new_size.x = size.x * scale.x;
    new_size.y = size.y * scale.y;
    new_pos.x = pos.x + ((size.x - new_size.x) / 2);
    new_pos.y = pos.y + ((size.y - new_size.y) / 2);
    sfRectangleShape_setScale(but.button, scale);
    sfRectangleShape_setPosition(but.button, new_pos);
}

void animation_circle_none(game_t *main_s, circle_but *but)
{
    sfVector2f scale_2 = {1, 1};

    sfCircleShape_setScale(but->button, scale_2);
    sfCircleShape_setPosition(but->button, but->original_pos);
}

void animation_circle_clic(game_t *main, circle_but but)
{
    sfFloatRect size = sfCircleShape_getGlobalBounds(but.button);
    sfVector2f pos = sfCircleShape_getPosition(but.button);
    sfVector2f new_size;
    sfVector2f new_pos;
    sfVector2f scale = {0.7, 0.7};
    sfVector2f scale_2 = {1, 1};

    new_size.x = size.width * scale.x;
    new_size.y = size.height * scale.y;
    new_pos.x = pos.x + ((size.width - new_size.x) / 2);
    new_pos.y = pos.y + ((size.height - new_size.y) / 2);
    sfCircleShape_setScale(but.button, scale);
    sfCircleShape_setPosition(but.button, new_pos);
    sfRenderWindow_drawCircleShape(main->win, but.button, NULL);
}
