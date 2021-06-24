/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init text
*/

#include "include/defender.h"

void init_text(game_t *main_s, info_t info, text_t *text)
{
    text->font = sfFont_createFromFile(info.path);
    text->text = sfText_create();
    sfText_setString(text->text, info.str);
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, info.size.x);
    sfText_setColor(text->text, info.color);
    sfText_setPosition(text->text, info.pos);
}