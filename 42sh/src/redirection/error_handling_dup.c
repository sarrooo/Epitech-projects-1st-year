/*
** EPITECH PROJECT, 2021
** minishell2
** File description:
** error_handling_dup
*/

#include "shell42.h"

int perror_return(char *function_name)
{
    perror(function_name);
    return (1);
}

int error_handling_dup_double_in(cmd_list_t *cmd)
{
    close(cmd->pipefd[1]);
    cmd->fd_stdin = dup(0);
    if (cmd->fd_stdin == -1)
        return (perror_return("dup"));
    cmd->fd_input = cmd->pipefd[0];
    if (dup2(cmd->pipefd[0], 0) == -1)
        return (perror_return("dup2"));
    close(cmd->pipefd[0]);
    return (0);
}

int error_handling_dup_out(cmd_list_t *cmd, int fd)
{
    cmd->fd_stdout = dup(1);
    if (cmd->fd_stdout == -1)
        return (perror_return("dup"));
    if (dup2(fd, 1) == -1)
        return (perror_return("dup2"));
    return (0);
}

int error_handling_dup_in(cmd_list_t *cmd, int fd)
{
    cmd->fd_stdin = dup(0);
    if (cmd->fd_stdin == -1)
        return (perror_return("dup"));
    if (dup2(fd, 0) == -1)
        return (perror_return("dup2"));
    return (0);
}