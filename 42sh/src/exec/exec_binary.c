/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** exec_binary
*/

#include "shell42.h"

char *print_error_message(int status)
{
    char *error_message;

    if (WTERMSIG(status) == 8) {
        error_message = malloc(sizeof(char) * 19);
        error_message = strdup("Floating exception");
    }
    else
        error_message = strdup(strsignal(WTERMSIG(status)));
    if (WCOREDUMP(status)) {
        error_message =
        realloc(error_message, sizeof(char) * (strlen(error_message) + 16));
        error_message = strcat(error_message, " (core dumped)\n");
    }
    else {
        error_message =
        realloc(error_message, sizeof(char) * (strlen(error_message) + 1));
        error_message = strcat(error_message, "\n");
    }
    write(2, error_message, strlen(error_message));
    free(error_message);
}

int child_execute_command(char **args, env_list_t *env)
{
    char **env_arr = env_list_to_array(env);
    char *null_args[] = {"", NULL};

    if (args[1] != NULL)
        execve(args[0], args, env_arr);
    else
        execve(args[0], null_args, env_arr);
    if (errno == ENOEXEC) {
        dprintf(2, "%s: Exec format error. Wrong Architecture.\n", args[0]);
        destroy_array(&env_arr);
        exit(1);
    }
    destroy_array(&env_arr);
    exit(255);
}

int wait_command(pid_t pid)
{
    int status;

    waitpid(pid, &status, WCONTINUED);
    if (WIFSIGNALED(status)) {
        print_error_message(status);
        return (WTERMSIG(status) + 128);
    }
    return (WEXITSTATUS(status));
}

int execute_binairy(head_t *head, cmd_list_t *cmd, env_list_t *env)
{
    int status;
    pid_t *pid_array = head->pipe_info.pid_array;
    pid_t pid = fork();

    if (pid != 0) {
        if (head->pipe_info.is_in_pipe == 1) {
            stock_pipe_pid(head, pid);
            return 1;
        } else {
            return wait_command(pid);
        }
    } else
        child_execute_command(cmd->argument, env);
    return (0);
}

int binary_command(head_t *head, cmd_list_t *cmd)
{
    int status = 0;

    if (access(cmd->argument[0], F_OK) != 0) {
        exec_error_message(cmd->argument[0], ": Command not found.\n");
        head->exit_status = 1;
        return 1;
    }
    status = execute_binairy(head, cmd, head->env);
    if (status == 255) {
        exec_error_message(cmd->argument[0], ": Permission denied.\n");
        head->exit_status = 1;
        return 1;
    }
    head->exit_status = status;
    return status;
}