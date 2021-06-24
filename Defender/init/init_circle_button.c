/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** manage circle button
*/

#include "include/defender.h"

void set_circle_pos(sfCircleShape *but, int x, int y)
{
    sfVector2f position = {x, y};

    sfCircleShape_setPosition(but, position);
}

void set_circle_button(char *path, circle_but *but)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    but->button = sfCircleShape_create();
    sfTexture_setSmooth(texture, sfTrue);
    sfCircleShape_setTexture(but->button, texture, sfTrue);
    but->texture = texture;
}

void circle_button(game_t *main_s, info_t info, circle_but *but)
{
    int len;
    sfVector2f pos = info.pos;
    int radian = info.radian;
    int rad = info.radian;
    int i = 0;

    but->original_pos = pos;
    set_circle_button(info.path, but);
    info.path = info.path + 13;
    len = my_strlen(info.path) - 3;
    sfCircleShape_setRadius(but->button, rad);
    set_circle_pos(but->button, pos.x, pos.y);
    but->name = malloc(sizeof(char) * len);
    for (i = 0; i < len - 1; i++)
        but->name[i] = info.path[i];
    but->name[i] = '\0';
    but->callback = info.callback;
}