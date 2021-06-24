/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** where
*/

#include "shell42.h"

void is_a_builtin(char *cmd)
{
    char *list[10] = {"echo", "setenv", "unsetenv", "cd", "exit",
                    "where", "which", "foreach", "if", "repeat"};

    for (int x = 0; x < 10; x++) {
        if (strcmp(list[x], cmd) == 0)
            printf("%s is a shell built-in\n", cmd);
    }
}

void is_in_path(char *cmd, char **path)
{
    char *slash;
    char *bin;

    for (int x = 0; path[x] != NULL; x++) {
        slash = malloc(sizeof(char) * strlen(path[x]) + 2);
        strcpy(slash, path[x]);
        strcat(slash, "/");
        bin = malloc(sizeof(char) * strlen(slash) + strlen(cmd) + 1);
        strcpy(bin, slash);
        strcat(bin, cmd);
        if (access(bin, X_OK) == 0)
            printf("%s\n", bin);
        free(slash);
        free(bin);
        free(path[x]);
    }
    free(path);
}

void builtin_where(head_t *head, char **cmd)
{
    alias_t *alias = head->alias;
    env_list_t *list = head->env;
    char **path = get_path_arr(head->env);
    int inc = 0;

    while (cmd[1] && alias != NULL) {
        if (strcmp(alias->alias, cmd[1]) == 0) {
            printf("%s is aliased to ", alias->alias);
            for (; alias->command[inc + 1] != NULL; inc++)
                printf("%s ", alias->command[inc]);
            printf("%s\n", alias->command[inc]);
        }
        alias = alias->next;
    }
    if (cmd[1]) {
        is_a_builtin(cmd[1]);
        is_in_path(cmd[1], path);
    }
    else
        printf("where: Too few arguments.\n");
}