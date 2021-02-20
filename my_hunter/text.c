/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** text my_hunter
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

char *best_score(int score)
{
    FILE *fd = fopen("hight_score.txt", "r+");
    char *str = malloc(sizeof(char) * 5);
    int i = 0;

    if (fd == NULL) {
        my_printf("miss the file \"hight_score.txt\"\nPlease make \"make\"");
        return (NULL);
    }
    fread(str, 1, 4, fd);
    str[4] = 0;
    for (i = 0; str[i] < 58 && str[i] > 47 && str[i] != 0; i++);
    str[i] = 0;
    if (i = 0)
        fwrite("0", sizeof(char), 1, fd);
    if (my_strcmp(str, str_int(score)) > 0) {
        fclose(fd);
        fopen("hight_score.txt", "w");
        fwrite(str_int(score), sizeof(char), my_strlen(str_int(score)), fd);
    }
    fclose(fd);
    return (str);
}

sfText *text_score(sfRenderWindow *win, int score)
{
    sfText *score_str = sfText_create();
    sfVector2u size = sfRenderWindow_getSize(win);
    sfVector2f pos = {1265, 25};
    sfFont *font = sfFont_createFromFile("image/jungle/jungle.ttf");
    char *s1 = str_int(score);
    char *s_str = str_cat("Score: ", str_int(score));
    char *best_str = best_score(score);

    if (best_str != NULL)
        text_best(win, score, best_str);
    sfText_setString(score_str, s_str);
    sfText_setFont(score_str, font);
    sfText_setCharacterSize(score_str, 40);
    sfText_setColor(score_str, sfWhite);
    sfText_setPosition(score_str, pos);
    sfRenderWindow_drawText(win, score_str, NULL);
    sfText_destroy(score_str);
    sfFont_destroy(font);
    free(s_str);
}

sfText *text_life(sfRenderWindow *win, int score)
{
    sfText *score_str = sfText_create();
    sfVector2u size = sfRenderWindow_getSize(win);
    sfVector2f pos = {25, 25};
    sfFont *font = sfFont_createFromFile("image/jungle/jungle.ttf");
    char *s1 = str_int(score);
    char *s_str = str_cat("Lives: ", str_int(3 - score));

    sfText_setString(score_str, s_str);
    sfText_setFont(score_str, font);
    sfText_setCharacterSize(score_str, 40);
    sfText_setColor(score_str, sfWhite);
    sfText_setPosition(score_str, pos);
    sfRenderWindow_drawText(win, score_str, NULL);
    sfText_destroy(score_str);
    sfFont_destroy(font);
    free(s_str);
}

void text_end(sfRenderWindow *win, int *score)
{
    sfText *score_str = sfText_create();
    sfVector2u size = sfRenderWindow_getSize(win);
    sfFont *font = sfFont_createFromFile("image/jungle/jungle.ttf");
    char *s_str = str_cat("Your Score: ", str_int(score[0]));
    sfVector2f pos = {510, 180};

    sfText_setString(score_str, s_str);
    sfText_setFont(score_str, font);
    sfText_setCharacterSize(score_str, 80);
    sfText_setColor(score_str, sfBlack);
    sfText_setPosition(score_str, pos);
    sfRenderWindow_drawText(win, score_str, NULL);
    sfText_destroy(score_str);
    sfFont_destroy(font);
    free(s_str);
}

void text_start(sfRenderWindow *win)
{
    sfText *score_str = sfText_create();
    sfVector2u size = sfRenderWindow_getSize(win);
    sfFont *font = sfFont_createFromFile("image/start/start.ttf");
    char *s_str = "My \"Jungle\" Hunter";
    sfVector2f pos = {380, 160};

    sfText_setString(score_str, s_str);
    sfText_setFont(score_str, font);
    sfText_setCharacterSize(score_str, 80);
    sfText_setColor(score_str, sfBlack);
    sfText_setPosition(score_str, pos);
    sfRenderWindow_drawText(win, score_str, NULL);
    sfText_destroy(score_str);
    sfFont_destroy(font);
}
