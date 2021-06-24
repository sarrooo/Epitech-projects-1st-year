/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** get_var_funcs
*/

#include "shell42.h"

int in_dquote(char *cmd)
{
    int inhib = 0;
    int indquote = -1;

    for (int i = 0; cmd[i]; i++) {
        if (cmd[i] == 34)
            indquote *= -1;
        if (cmd[i] == '$' && inhib == 0)
            return (indquote);
        if (cmd[i] == '\\')
            inhib = 1;
        else
            inhib = 0;
    }
    return (0);
}

void check_indquote(char *cmd, int *i, int *k)
{
    if (in_dquote(cmd) == 1) {
        *i -= 1;
        *k += 2;
    }
}

int get_var_pos(char *cmd)
{
    int inquote = -1;
    int inhib = 0;

    for (int i = 0; cmd[i]; i++) {
        if (cmd[i] == 39)
            inquote *= -1;
        if (cmd[i] == '$' && inquote == -1 && inhib == 0)
            return (i);
        if (cmd[i] == '\\')
            inhib = 1;
        else
            inhib = 0;
    }
}

char *get_name(char *cmd)
{
    int inquote = -1;
    int i = get_var_pos(cmd);
    int j = 0;
    char *name;

    name = malloc(sizeof(char) * (strlen(cmd) - i + 1));
    for (i = i + 1; cmd[i] && cmd[i] != ' ' && cmd[i] != 34; i++, j++)
        name[j] = cmd[i];
    name[j] = '\0';
    return (name);
}