/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** redirection_error_handling
*/

#include "shell42.h"

static int is_file_redirection(char *str)
{
    if (str[0] == '|' || str[0] == '&')
        return true;
    if (str[0] == ';' || str[0] == '>')
        return true;
    if (str[0] == '<' || str[0] == '(')
        return true;
    if (str[0] == '<' || str[0] == ')')
        return true;
    if (str[0] == '`' || str[0] == 39)
        return true;
    return false;
}

static int is_separator(char *str)
{
    if (str[0] == '|' || (str[0] == '&' && str[1] == '&'))
        return true;
    return false;
}

static int check_name_for_redirect(char **array, int i)
{
    if (array[i][0] == '>' || array[i][0] == '<') {
        if (array[i + 1] == NULL || is_file_redirection(array[i + 1])) {
            write(2, "Missing name for redirect.\n", 27);
            return true;
        }
    }
    return false;
}

int redirection_error_handling(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        if (check_name_for_redirect(array, i))
            return true;
    }
    return false;
}