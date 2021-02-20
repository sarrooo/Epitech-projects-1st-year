/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** mange text 2
*/

#include "include/my.h"

void text_score_final(sfRenderWindow *win, list *l_a)
{
    sfText *score_str = sfText_create();
    sfVector2u size = sfRenderWindow_getSize(win);
    sfFont *font = sfFont_createFromFile("police/candy.ttf");
    char *s_str = str_cat("Your score: ", str_int(l_a->score));
    sfVector2f pos = {220, 150};

    sfText_setString(score_str, s_str);
    sfText_setFont(score_str, font);
    sfText_setCharacterSize(score_str, 50);
    sfText_setColor(score_str, sfWhite);
    sfText_setPosition(score_str, pos);
    sfRenderWindow_drawText(win, score_str, NULL);
    sfText_destroy(score_str);
    sfFont_destroy(font);
}

void text_hight_score_final(sfRenderWindow *win, list *l_a)
{
    sfText *score_str = sfText_create();
    sfVector2u size = sfRenderWindow_getSize(win);
    sfFont *font = sfFont_createFromFile("police/candy.ttf");
    char *best_str = l_a->high_score;
    char *s_str = "Miss file";
    sfVector2f pos = {240, 200};

    if (best_str != NULL)
        s_str = str_cat("High score: ", best_str);
    sfText_setString(score_str, s_str);
    sfText_setFont(score_str, font);
    sfText_setCharacterSize(score_str, 40);
    sfText_setColor(score_str, sfRed);
    sfText_setPosition(score_str, pos);
    sfRenderWindow_drawText(win, score_str, NULL);
    sfText_destroy(score_str);
    sfFont_destroy(font);
}

void text_high_score(sfRenderWindow *win, list *l_a)
{
    sfText *score_str = sfText_create();
    sfVector2u size = sfRenderWindow_getSize(win);
    sfFont *font = sfFont_createFromFile("police/candy.ttf");
    char *best_str = l_a->high_score;
    char *s_str = "Miss file";
    sfVector2f pos = {10, 35};

    if (best_str != NULL)
        s_str = str_cat("High score: ", best_str);
    sfText_setString(score_str, s_str);
    sfText_setFont(score_str, font);
    sfText_setCharacterSize(score_str, 25);
    sfText_setColor(score_str, sfRed);
    sfText_setPosition(score_str, pos);
    sfRenderWindow_drawText(win, score_str, NULL);
    sfText_destroy(score_str);
    sfFont_destroy(font);
}

void text_level(sfRenderWindow *win, list *l_a)
{
    sfText *score_str = sfText_create();
    sfVector2u size = sfRenderWindow_getSize(win);
    sfFont *font = sfFont_createFromFile("police/candy.ttf");
    char *s_str = str_cat("Level: ", str_int(l_a->level / 50));
    sfVector2f pos = {300, 5};

    sfText_setString(score_str, s_str);
    sfText_setFont(score_str, font);
    sfText_setCharacterSize(score_str, 50);
    sfText_setColor(score_str, sfRed);
    sfText_setPosition(score_str, pos);
    sfRenderWindow_drawText(win, score_str, NULL);
    sfText_destroy(score_str);
    sfFont_destroy(font);
}

void text_level_final(sfRenderWindow *win, list *l_a)
{
    sfText *score_str = sfText_create();
    sfVector2u size = sfRenderWindow_getSize(win);
    sfFont *font = sfFont_createFromFile("police/candy.ttf");
    char *s_str = str_cat("Level: ", str_int(l_a->level / 50));
    sfVector2f pos = {320, 240};

    sfText_setString(score_str, s_str);
    sfText_setFont(score_str, font);
    sfText_setCharacterSize(score_str, 40);
    sfText_setColor(score_str, sfWhite);
    sfText_setPosition(score_str, pos);
    sfRenderWindow_drawText(win, score_str, NULL);
    sfText_destroy(score_str);
    sfFont_destroy(font);
}