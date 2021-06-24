/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** stock in char ** an str, words are separated by only space
*/

#include <stdlib.h>
#include <stddef.h>
#include "tools.h"

int get_quote_word(char const *str, int j, char **table, int a)
{
    int nb_l = 0;
    int y = 0;
    int quote = str[j++];

    for (nb_l = 0; str[j] != 0 && str[j] != quote; nb_l++, j++);
    if (quote != '`')
        table[a] = malloc(sizeof(char) * (nb_l + 1));
    else {
        table[a] = malloc(sizeof(char) * (nb_l + 3));
        table[a][y++] = '`';
    }
    for (int c = j - nb_l; str[c] != 0 && c < j; c++)
        table[a][y++] = str[c];
    if (quote != '`')
        table[a++][y] = '\0';
    else {
        table[a][y++] = '`';
        table[a++][y] = 0;
    }
    j++;
    return (j);
}

int get_not_quote_word(char const *str, int j, char **table, int a)
{
    int nb_l = 0;
    int y = 0;

    for (nb_l = 0; str[j] != 0 && check_alphanum_str(str, j) != 0; nb_l++)
        j++;
    table[a] = malloc(sizeof(char) * (nb_l + 1));
    for (int c = j - nb_l; str[c] != 0 && c < j; c++)
        table[a][y++] = str[c];
    table[a++][y] = '\0';
    return (j);
}

char **my_str_to_word_array(char const *str)
{
    char **table = malloc(sizeof(char *) * (count_words_str(str) + 1));
    int j = 0;
    int a = 0;

    while (str[j] != 0) {
        if (str[j] == 34 || str[j] == 39 || str[j] == '`') {
            j = get_quote_word(str, j, table, a);
            a++;
        }
        else if (check_alphanum_str(str, j) == 1){
            j = get_not_quote_word(str, j, table, a);
            a++;
        }
        if (str[j] != 0 && str[j] != 34 && check_alphanum_str(str, j) == 0)
            j++;
    }
    table[a] = NULL;
    return (table);
}