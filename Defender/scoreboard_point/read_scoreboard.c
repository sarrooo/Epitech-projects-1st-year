/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** read stored scoreboard
*/

#include "include/defender.h"

char *str_cat_score(char *s1, char *s2)
{
    char *dest = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
    int i = 0;

    for (i = 0; i < my_strlen(s1); i++)
        dest[i] = s1[i];
    for (int z = 0; z < my_strlen(s2); z++)
        dest[i++] = s2[z];
    dest[i] = 0;
    return (dest);
}

void sort_score_2(char **score, int nb_score, int i)
{
    int c = 0;

    for (int j = i + 1; j < nb_score; j++)
        if (my_getnbr(score[i]) < my_getnbr(score[j])) {
            c = my_getnbr(score[i]);
            score[i] = score[j];
            score[j] = str_int(c);
        }
}

void sort_score(char **score)
{
    int j;
    int c;
    int nb_score;

    for (nb_score = 0; score[nb_score] != NULL; nb_score++);
    for (int i = 0; i < nb_score - 1; i++) {
        sort_score_2(score, nb_score, i);
    }
}

void read_scoreboard(game_t *main_s)
{
    FILE *fd = fopen("scoreboard/score.txt", "r");
    size_t len = 1;
    ssize_t len_arg = 0;
    int j = 0;

    main_s->scoreboard_point = malloc(sizeof(char *) * 6);
    for (int i = 0; i < 6; i++)
        main_s->scoreboard_point[i] = NULL;
    if (fd == NULL)
        return;
    for (j = 0; len_arg != -1 && j < 6; j++) {
        len_arg = getline(&main_s->scoreboard_point[j], &len, fd);
        if (len_arg != -1 && main_s->scoreboard_point[j][len_arg - 1] == '\n')
            main_s->scoreboard_point[j][len_arg - 1] = 0;
    }
    main_s->scoreboard_point[j - 1] = NULL;
    fclose(fd);
    sort_score(main_s->scoreboard_point);
}