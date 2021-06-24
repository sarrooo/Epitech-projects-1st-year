/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** error_handling
*/

#include "shell42.h"

int error_handling_single_quote(char *str, int *i);
int check_quote(char *str, int *i);
int check_backtick(char *str, int *i);

static int error_handling_quote_backtick(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (check_backtick(str, &i))
            return true;
        if (check_quote(str, &i))
            return true;
        if (error_handling_single_quote(str, &i))
            return true;
    }
}

static int check_other_parentheses(char *str, int i)
{
    int j = 0;

    if (str[i] == '(') {
        for (j = i; str[j] != 0 && str[j] != ')'; j++);
        if (str[j] != ')') {
            write(2, "Too many ('s.\n", 14);
            return true;
        }
    }
    return false;
}

static int error_handling_parentheses(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (check_other_parentheses(str, i))
            return true;
    }
}

int read_error_handling(char *str)
{
    if (error_handling_quote_backtick(str))
        return true;
    return false;
}