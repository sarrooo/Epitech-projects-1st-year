/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** high score
*/

#include "include/my.h"

char *best_score_2(list *l_a, FILE *fd, char *str, int i)
{
    char *int_s = str_int(l_a->score);

    if (i = 0)
        fwrite("0", sizeof(char), 1, fd);
    if (my_getnbr(str) - 1 < (int)l_a->score) {
        fd = fopen("high_score.txt", "w");
        str = int_s;
        fwrite(int_s, sizeof(char), my_strlen(int_s), fd);
    }
    fclose(fd);
    return (str);
}

char *best_score(list *l_a)
{
    FILE *fd = fopen("high_score.txt", "r+");
    size_t ia = 0;
    char *str = malloc(sizeof(char *));
    int i = 0;
    char *int_s;

    if (fd == NULL) {
        my_printf("miss the file \"high_score.txt\"\nPlease make \"make\" ");
        return (NULL);
    }
    i = getline(&str, &ia, fd);
    str[i] = 0;
    str = best_score_2(l_a, fd, str, i);
    l_a->high_score = str;
    return (str);
}