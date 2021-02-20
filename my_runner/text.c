/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** text
*/

#include "include/my.h"

void text_start(sfRenderWindow *win)
{
    sfText *score_str = sfText_create();
    sfVector2u size = sfRenderWindow_getSize(win);
    sfFont *font = sfFont_createFromFile("police/candy.ttf");
    char *s_str = "<Sweet> Runner";
    sfVector2f pos = {180, 90};

    sfText_setString(score_str, s_str);
    sfText_setFont(score_str, font);
    sfText_setCharacterSize(score_str, 60);
    sfText_setColor(score_str, sfBlue);
    sfText_setPosition(score_str, pos);
    sfRenderWindow_drawText(win, score_str, NULL);
    sfText_destroy(score_str);
    sfFont_destroy(font);
}

void text_pause(sfRenderWindow *win)
{
    sfText *score_str = sfText_create();
    sfVector2u size = sfRenderWindow_getSize(win);
    sfFont *font = sfFont_createFromFile("police/candy.ttf");
    char *s_str = "PAUSED";
    sfVector2f pos = {265, 100};

    sfText_setString(score_str, s_str);
    sfText_setFont(score_str, font);
    sfText_setCharacterSize(score_str, 75);
    sfText_setColor(score_str, sfRed);
    sfText_setPosition(score_str, pos);
    sfRenderWindow_drawText(win, score_str, NULL);
    sfText_destroy(score_str);
    sfFont_destroy(font);
}

void text_score(sfRenderWindow *win, list *l_a)
{
    sfText *score_str = sfText_create();
    sfVector2u size = sfRenderWindow_getSize(win);
    sfFont *font = sfFont_createFromFile("police/candy.ttf");
    char *s_str = str_cat("Score: ", str_int(l_a->score));
    sfVector2f pos = {10, 5};

    sfText_setString(score_str, s_str);
    sfText_setFont(score_str, font);
    sfText_setCharacterSize(score_str, 30);
    sfText_setColor(score_str, sfRed);
    sfText_setPosition(score_str, pos);
    sfRenderWindow_drawText(win, score_str, NULL);
    sfText_destroy(score_str);
    sfFont_destroy(font);
}

void text_lose(sfRenderWindow *win)
{
    sfText *score_str = sfText_create();
    sfVector2u size = sfRenderWindow_getSize(win);
    sfFont *font = sfFont_createFromFile("police/candy.ttf");
    char *s_str = "YOU LOSE";
    sfVector2f pos = {180, 50};

    sfText_setString(score_str, s_str);
    sfText_setFont(score_str, font);
    sfText_setCharacterSize(score_str, 100);
    sfText_setColor(score_str, sfRed);
    sfText_setPosition(score_str, pos);
    sfRenderWindow_drawText(win, score_str, NULL);
    text_end_key(win);
    sfText_destroy(score_str);
    sfFont_destroy(font);
}

void text_win(sfRenderWindow *win)
{
    sfText *score_str = sfText_create();
    sfVector2u size = sfRenderWindow_getSize(win);
    sfFont *font = sfFont_createFromFile("police/candy.ttf");
    char *s_str = "YOU WIN";
    sfVector2f pos = {200, 50};

    sfText_setString(score_str, s_str);
    sfText_setFont(score_str, font);
    sfText_setCharacterSize(score_str, 100);
    sfText_setColor(score_str, sfRed);
    sfText_setPosition(score_str, pos);
    sfRenderWindow_drawText(win, score_str, NULL);
    text_end_key(win);
    sfText_destroy(score_str);
    sfFont_destroy(font);
}