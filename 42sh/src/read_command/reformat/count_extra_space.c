/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** count_extra_space
*/

#include "shell42.h"

static void count_space_double_separator(char *str, int i,
int *index_new, char separator)
{
    if (i != 0 && str[i - 1] != ' ' && str[i - 1] != separator)
        *index_new += 1;
    if (str[i] != 0 && str[i + 1] != 0 && str[i + 1] != separator)
        *index_new += 1;
}

static void count_space_simple_separator(char *str, int i,
int *index_new, char separator)
{
    if (i != 0 && str[i - 1] != ' ')
        *index_new += 1;
    if (str[i] != 0 && str[i + 1] != 0 && str[i + 1] != ' ')
        *index_new += 1;
}

static void count_space_quote_aux(char *line, int *i, int *nb_space)
{
    if (line[*i] == '`') {
        if (*i != 0 && line[*i - 1] != ' ')
            *nb_space += 1;
        *i += 1;
        *nb_space += 1;
        for (*i; line[*i] != 0 && line[*i] != '`'; *i += 1, *nb_space += 1);
        if (line[*i] != 0 && line[*i + 1] != ' ')
            *nb_space += 1;
    }
}

static void count_space_quote(char *line, int *i, int *nb_space)
{
    if (line[*i] == 39) {
        if (*i != 0 && line[*i - 1] != ' ')
            *nb_space += 1;
        *i += 1;
        *nb_space += 1;
        for (*i; line[*i] != 0 && line[*i] != 39; *i += 1, *nb_space += 1);
        if (line[*i] != 0 && line[*i + 1] != ' ')
            *nb_space += 1;
    }
    if (line[*i] == 34) {
        if (*i != 0 && line[*i - 1] != ' ')
            *nb_space += 1;
        *i += 1;
        *nb_space += 1;
        for (*i; line[*i] != 0 && line[*i] != 34; *i += 1, *nb_space += 1);
        if (line[*i] != 0 && line[*i + 1] != ' ')
            *nb_space += 1;
    }
    count_space_quote_aux(line, i, nb_space);
}

int count_extra_space(char *line)
{
    int nb_extra_space = 0;

    for (int i = 0; line[i] != 0; i++) {
        nb_extra_space++;
        count_space_quote(line, &i, &nb_extra_space);
        if (is_simple_separator(line[i]))
            count_space_simple_separator(line, i, &nb_extra_space, line[i]);
        if (is_double_separator(line[i]))
            count_space_double_separator(line, i, &nb_extra_space, line[i]);
    }
    return nb_extra_space;
}