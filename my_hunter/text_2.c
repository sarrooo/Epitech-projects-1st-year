/*
** EPITECH PROJECT, 2020
** my_hunter
** File description: text for hight score
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <time.h>
#include "lib/my.h"
#include "include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

sfText *text_best(sfRenderWindow *win, int score, char *s1)
{
    sfText *score_str = sfText_create();
    sfVector2u size = sfRenderWindow_getSize(win);
    sfVector2f pos = {625, 25};
    sfFont *font = sfFont_createFromFile("image/jungle/jungle.ttf");
    char *s_str = str_cat("Best Score: ", s1);

    sfText_setString(score_str, s_str);
    sfText_setFont(score_str, font);
    sfText_setCharacterSize(score_str, 40);
    sfText_setColor(score_str, sfBlack);
    sfText_setPosition(score_str, pos);
    sfRenderWindow_drawText(win, score_str, NULL);
    sfText_destroy(score_str);
    sfFont_destroy(font);
    free(s_str);
}
