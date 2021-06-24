/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** execute_command
*/

#include "shell42.h"

int wait_command(pid_t pid);

static int is_slash(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '/')
            return true;
    return false;
}

static char *strcat_path(char *path, char *bin)
{
    char *path_bin;

    path_bin =
    malloc(sizeof(char) * (strlen(path) + strlen(bin) + 2));
    path_bin[0] = 0;
    path_bin = strcat(path_bin, path);
    path_bin = strcat(path_bin, "/");
    path_bin = strcat(path_bin, bin);
    return path_bin;
}

static int try_command(head_t *head, cmd_list_t *cmd, char **env)
{
    char **path = get_path_env(head);
    char *path_bin;
    char *null_args[] = {"", NULL};
    char **args = cmd->argument;

    for (int i = 0; path[i] != NULL; i++) {
        path_bin = strcat_path(path[i], args[0]);
        if (cmd->argument[1] != NULL)
            execve(path_bin, args, env);
        else
            execve(path_bin, null_args, env);
        free(path_bin);
    }
    exec_error_message(cmd->argument[0], ": Command not found.\n");
    destroy_array(&path);
    exit(1);
}

static int exec_command(head_t *head, cmd_list_t *cmd, char **env)
{
    int status;
    pid_t pid = fork();
    int if_not_path = 0;

    if (pid != 0) {
        if (head->pipe_info.is_in_pipe == 1) {
            stock_pipe_pid(head, pid);
            return 1;
        }
        else
            return wait_command(pid);
    } else {
        try_command(head, cmd, env);
    }
    return (0);
}

int manage_command(head_t *head)
{
    cmd_list_t *cmd = head->cmd_list;
    char **env;
    int status = 0;

    if (check_globbing(head, head->cmd_list->argument) == 1)
        return 1;
    if (is_slash(cmd->argument[0]) == false) {
        env = env_list_to_array(head->env);
        status = exec_command(head, cmd, env);
        destroy_array(&env);
        head->exit_status = status;
        return status;
    } else {
        if (binary_command(head, cmd))
            return 1;
    }
    return 0;
}