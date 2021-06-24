/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** score for win screen
*/

#include "include/defender.h"

void write_score(game_t *main_s, int score)
{
    FILE *fd = fopen("scoreboard/score.txt", "w+");
    int len_score;

    for (int i = 0; main_s->scoreboard_point[i] != NULL; i++) {
        len_score = my_strlen(main_s->scoreboard_point[i]);
        fwrite(main_s->scoreboard_point[i], 1, len_score, fd);
        if (main_s->scoreboard_point[i + 1] != NULL)
            fwrite("\n", 1, 1, fd);
    }
    fclose(fd);
}

void score_win_screen(game_t *main_s)
{
    int score;
    int index = 0;
    int i;

    score = main_s->point_life * 100;
    score = score + main_s->gold_point;
    if (main_s->map.if_win == 2)
        score = score - 1000;
    for (i = 0; main_s->scoreboard_point[i] != NULL; i++)
        if (my_getnbr(main_s->scoreboard_point[i]) < score)
            index = i + 1;
    if (i == 5 && index == 0)
        return;
    else if (i != 5)
        main_s->scoreboard_point[i] = str_int(score);
    else
        main_s->scoreboard_point[index - 1] = str_int(score);
    sort_score(main_s->scoreboard_point);
    write_score(main_s, score);
}