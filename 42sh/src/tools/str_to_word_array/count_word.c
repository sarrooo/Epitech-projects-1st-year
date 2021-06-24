/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** count_word
*/

#include "shell42.h"

int check_alphanum_str(char const *str, int j)
{
    if (str[j] > 0 && str[j] < 33)
        return (0);
    if (str[j] == 127)
        return (0);
    return (1);
}

static int count_word_quote(char const *str, int j)
{
    if (str[j] != 0)
        j++;
    for (j; str[j] != 0 && str[j] != 34; j++);
    if (str[j] != 0)
        j++;
    return (j);
}

static int count_word_not_quote(char const *str, int j)
{
    while (str[j] != 0 && check_alphanum_str(str, j) == 1 && str[j] != 34)
        j++;
    if (str[j] == 34)
        j++;
    return (j);
}

int count_words_str(char const *str)
{
    int length = strlen(str);
    int nb_words = 0;
    int j = 0;

    while (str[j] != 0 && j < length) {
        if (str[j] == 34 && str[j] != 0 && str[j + 1] != 0) {
            nb_words = nb_words + 1;
            j = count_word_quote(str, j);
        }
        if (check_alphanum_str(str, j) == 1 && str[j] != 34 && str[j] != 0) {
            nb_words = nb_words + 1;
            j = count_word_not_quote(str, j);
        }
        if (check_alphanum_str(str, j) == 0 && str[j] != 34)
            j++;
    }
    return (nb_words);
}