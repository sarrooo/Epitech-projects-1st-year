/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** separator
*/

#include "shell42.h"

static int add_space_double_separator(char *str, int i, char separator)
{
    if (str[i + 1] != 0 && str[i] == separator &&
    i != 0 && str[i - 1] == separator && str[i + 1] == separator) {
        return true;
    }
    if (str[i + 1] != 0 && str[i] != ' ' &&
    str[i] != separator && str[i + 1] == separator)
        return true;
    if (str[i + 1] != 0 && str[i] == separator &&
    i != 0 && str[i + 1] != ' ' && str[i + 1] != separator)
        return true;
    return false;
}

static int add_space_simple_separator(char *str, int i, char separator)
{
    if (str[i + 1] != 0 && str[i] != ' ' && str[i + 1] == separator)
        return true;
    if (str[i + 1] != 0 && str[i] == separator && str[i + 1] != ' ')
        return true;
    return false;
}

void space_double_separator(char *str, char *new_str, int i, int *index_new)
{
    if (is_double_separator(str[i]) &&
    add_space_double_separator(str, i, str[i]) == true) {
        if (new_str[*index_new - 1] != ' ') {
            new_str[*index_new] = ' ';
            *index_new += 1;
        }
    }
    if (is_double_separator(str[i + 1]) &&
    add_space_double_separator(str, i, str[i + 1]) == true) {
        if (new_str[*index_new - 1] != ' ') {
            new_str[*index_new] = ' ';
            *index_new += 1;
        }
    }
}

void add_space_separator(char *str, char *new_str, int i, int *index_new)
{
    if (is_simple_separator(str[i]) &&
    add_space_simple_separator(str, i, str[i]) == true) {
        if (new_str[*index_new - 1] != ' ') {
            new_str[*index_new] = ' ';
            *index_new += 1;
        }
    }
    if (is_simple_separator(str[i + 1]) &&
    add_space_simple_separator(str, i, str[i + 1]) == true) {
        if (new_str[*index_new - 1] != ' ') {
            new_str[*index_new] = ' ';
            *index_new += 1;
        }
    }
    space_double_separator(str, new_str, i, index_new);
}