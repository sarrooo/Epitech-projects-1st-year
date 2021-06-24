/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** manage_builtin
*/

#include "shell42.h"

int search_alias_builtin(head_t *head, char *command)
{
    if (strcmp(command, "alias") == 0) {
        builtin_alias(head, head->cmd_list->argument);
        return 1;
    }
    if (strcmp(command, "unalias") == 0) {
        builtin_unalias(head, head->cmd_list->argument);
        return 1;
    }
    return 0;
}

int search_where_wich_builtin(head_t *head, char *command)
{
    if (strcmp(command, "where") == 0) {
        builtin_where(head, head->cmd_list->argument);
        return 1;
    }
    if (strcmp(command, "which") == 0) {
        builtin_which(head, head->cmd_list->argument);
        return 1;
    }
    return 0;
}

int search_env_builtin(head_t *head, char *command)
{
    if (strcmp(command, "setenv") == 0) {
        builtin_setenv(head, head->cmd_list->argument);
        return 1;
    }
    if (strcmp(command, "env") == 0) {
        builtin_env(head, head->cmd_list->argument);
        return 1;
    }
    if (strcmp(command, "unsetenv") == 0) {
        builtin_unsetenv(head, head->cmd_list->argument);
        return 1;
    }
    return 0;
}

int search_cd_exit_builtin(head_t *head, char *command)
{
    if (strcmp(command, "exit") == 0) {
        builtin_exit(head, head->cmd_list->argument);
        return 1;
    }
    if (strcmp(command, "cd") == 0) {
        builtin_cd(head, &head->cmd_list->argument);
        return 1;
    }
    return 0;
}

int manage_builtin(head_t *head)
{
    char *command = head->cmd_list->argument[0];

    if (search_env_builtin(head, command))
        return 1;
    if (search_cd_exit_builtin(head, command))
        return 1;
    if (search_where_wich_builtin(head, command))
        return 1;
    if (search_alias_builtin(head, command))
        return 1;
    if (search_foreach_if_repeat_builtin(head, command, 0))
        return 1;
    if (strcmp(command, "set") == 0) {
        builtin_set(head, head->cmd_list->argument);
        return 1;
    }
    if (strcmp(command, "unset") == 0) {
        builtin_unset(head, head->cmd_list->argument);
        return 1;
    }
    return 0;
}