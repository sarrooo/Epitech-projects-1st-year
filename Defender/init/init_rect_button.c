/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** manage rect button
*/

#include "include/defender.h"

void set_rect_pos(sfRectangleShape *but, int x, int y)
{
    sfVector2f position = {x, y};

    sfRectangleShape_setPosition(but, position);
}

void set_rect_button(char *path, rect_but *but)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    but->button = sfRectangleShape_create();
    sfTexture_setSmooth(texture, sfTrue);
    sfRectangleShape_setTexture(but->button, texture, sfTrue);
    but->texture = texture;
}

void rect_button(game_t *main_s, info_t info, rect_but *but)
{
    int len_path;
    sfVector2f pos = info.pos;
    sfVector2f size = info.size;
    int i = 0;

    but->original_pos = pos;
    set_rect_button(info.path, but);
    info.path = info.path + 13;
    len_path = my_strlen(info.path) - 3;
    sfRectangleShape_setSize(but->button, size);
    set_rect_pos(but->button, pos.x, pos.y);
    but->name = malloc(sizeof(char) * len_path);
    for (i = 0; i < len_path - 1; i++)
        but->name[i] = info.path[i];
    but->name[i] = '\0';
    but->callback = info.callback;
}