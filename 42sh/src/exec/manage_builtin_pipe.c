/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** manage_builtin_pipe
*/

#include "shell42.h"

static int is_builtin(char *command)
{
    if (strcmp(command, "setenv") == 0 || strcmp(command, "env") == 0)
        return true;
    if (strcmp(command, "unsetenv") == 0 || strcmp(command, "where") == 0)
        return true;
    if (strcmp(command, "wich") == 0 || strcmp(command, "alias") == 0)
        return true;
    if (strcmp(command, "unalias") == 0 || strcmp(command, "exit") == 0)
        return true;
    if (strcmp(command, "cd") == 0 || strcmp(command, "set") == 0)
        return true;
    if (strcmp(command, "unset") == 0)
        return true;
    return false;
}

static int exec_builtin_pipe(head_t *head, char *command)
{
    if (search_env_builtin(head, command))
        return 1;
    if (search_cd_exit_builtin(head, command))
        return 1;
    if (search_where_wich_builtin(head, command))
        return 1;
    if (search_alias_builtin(head, command))
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

int manage_builtin_pipe(head_t *head)
{
    char *command = head->cmd_list->argument[0];
    pid_t pid;

    if (is_builtin(command) == false)
        return 0;
    pid = fork();
    if (pid != 0) {
        stock_pipe_pid(head, pid);
        return 1;
    } else {
        exec_builtin_pipe(head, command);
    }
    return (0);
}