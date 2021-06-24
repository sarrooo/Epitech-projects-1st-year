/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** backtick_quote
*/

#include "shell42.h"

int error_handling_single_quote(char *str, int *i)
{
    int j = 0;

    if (str[*i] == 39) {
        *i += 1;
        for (j = *i; str[j] != 0 && str[j] != 39; j++);
        if (str[j] == '\'')
            *i = j;
        else {
            write(2, "Unmatched '''\n", 15);
            return true;
        }
    }
    return false;
}

int check_quote(char *str, int *i)
{
    int j = 0;

    if (str[*i] == '\"') {
        *i += 1;
        for (j = *i; str[j] != 0 && str[j] != '\"'; j++);
        if (str[j] == '\"')
            *i = j;
        else {
            write(2, "Unmatched '\"'.\n", 15);
            return true;
        }
    }
    return false;
}

int check_backtick(char *str, int *i)
{
    int j = 0;

    if (str[*i] == '`') {
        *i += 1;
        for (j = *i; str[j] != 0 && str[j] != '`'; j++);
        if (str[j] == '`')
            *i = j;
        else {
            write(2, "Unmatched '`'.\n", 15);
            return true;
        }
    }
    return false;
}