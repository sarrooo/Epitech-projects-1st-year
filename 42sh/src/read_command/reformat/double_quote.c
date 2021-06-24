/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** double_quote
*/

#include "shell42.h"

static void copy_char(char *str, char *str_clean, int *index_str_clean, int *i)
{
    str_clean[*index_str_clean] = str[*i];
    *index_str_clean += 1;
    *i += 1;
}

static void space_before_quote(char *str, char *str_clean,
int *i, int *index_str_clean)
{
    if (*i != 0 && str[*i] != ' ' && str_clean[*index_str_clean - 1] != ' ') {
        str_clean[*index_str_clean] = str[*i];
        *index_str_clean += 1;
        *i += 1;
        str_clean[*index_str_clean] = ' ';
        *index_str_clean += 1;
    }
    else {
        if (*i == 0)
            *i += 1;
        str_clean[*index_str_clean] = str[*i];
        *index_str_clean += 1;
        *i += 1;
    }
}

static void space_after_quote(char *str, char *str_clean,
int *i, int *index_str_clean)
{
    if (str[*i] != 0 && str[*i] != ' ' &&
    str_clean[*index_str_clean - 1] != ' ') {
        str_clean[*index_str_clean] = ' ';
        *index_str_clean += 1;
        *i -= 1;
    }
    else if (str[*i] != 0) {
        copy_char(str, str_clean, index_str_clean, i);
        *i -= 1;
    }
}

static void get_str_between_quote(char *str, char *str_clean,
int *i, int *index_str_clean)
{
    for (i; str[*i] != 0 && str[*i] != 34; *i += 1) {
        str_clean[*index_str_clean] = str[*i];
        *index_str_clean += 1;
    }
}

void between_quote(char *str, char *str_clean, int *i, int *index_str_clean)
{
    if (str[*i] != 0 && str[*i + 1] != 0) {
        if (str[*i + 1] == 34 || str[*i] == 34) {
            space_before_quote(str, str_clean, i, index_str_clean);
            copy_char(str, str_clean, index_str_clean, i);
            get_str_between_quote(str, str_clean, i, index_str_clean);
            copy_char(str, str_clean, index_str_clean, i);
            space_after_quote(str, str_clean, i, index_str_clean);
        }
    }
}