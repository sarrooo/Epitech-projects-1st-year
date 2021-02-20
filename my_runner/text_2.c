/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** manage text
*/

#include "include/my.h"

void text_end_key(sfRenderWindow *win)
{
    sfText *score_str = sfText_create();
    sfVector2u size = sfRenderWindow_getSize(win);
    sfFont *font = sfFont_createFromFile("police/bubble.ttf");
    char *s_str = "Press ENTER to replay";
    sfVector2f pos = {220, 530};

    sfText_setString(score_str, s_str);
    sfText_setFont(score_str, font);
    sfText_setCharacterSize(score_str, 40);
    sfText_setColor(score_str, sfBlack);
    sfText_setPosition(score_str, pos);
    sfRenderWindow_drawText(win, score_str, NULL);
    sfText_destroy(score_str);
    sfFont_destroy(font);
}