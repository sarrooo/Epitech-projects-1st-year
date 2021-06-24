/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** wich
*/

#include "shell42.h"

int is_a_builtin2(char *cmd)
{
    char *list[10] = {"echo", "setenv", "unsetenv", "cd", "exit",
    "where", "which", "foreach", "if", "repeat"};

    for (int x = 0; x < 10; x++) {
        if (strcmp(list[x], cmd) == 0) {
            printf("%s: shell built-in command.\n", cmd);
            return (1);
        }
    }
    return (0);
}

void is_in_path2(char *cmd, char **path, int stop)
{
    char *slash;
    char *bin;

    for (int x = 0; path[x] != NULL; x++) {
        if (stop == 0) {
            slash = malloc(sizeof(char) * strlen(path[x]) + 2);
            strcpy(slash, path[x]);
            strcat(slash, "/");
            bin = malloc(sizeof(char) * strlen(slash) + strlen(cmd) + 1);
            strcpy(bin, slash);
            strcat(bin, cmd);
            if (access(bin, X_OK) == 0) {
                printf("%s\n", bin);
                stop = 1;
            }
            free(slash);
            free(bin);
        }
        free(path[x]);
    }
    free(path);
}

void builtin_which(head_t *head, char **cmd)
{
    alias_t *alias = head->alias;
    env_list_t *list = head->env;
    char **path = get_path_arr(list);
    int inc = 0;
    int stop = 0;

    while (cmd[1] && alias != NULL) {
        if (strcmp(alias->alias, cmd[1]) == 0 && stop == 0) {
            printf("%s      aliased to ", alias->alias);
            for (; alias->command[inc + 1] != NULL; inc++)
                printf("%s ", alias->command[inc]);
            printf("%s\n", alias->command[inc]);
            stop = 1;
        }
        alias = alias->next;
    }
    if (cmd[1] && stop == 0) {
        stop = is_a_builtin2(cmd[1]);
        is_in_path2(cmd[1], path, stop);
    } else if (!cmd[1])
        printf("which: Too few arguments.\n");
}