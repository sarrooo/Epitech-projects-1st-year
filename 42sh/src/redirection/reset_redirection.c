/*
** EPITECH PROJECT, 2021
** minishell_2
** File description:
** reset redirection at the end of the command line
*/

#include "shell42.h"

int reset_input_redirection(cmd_list_t *cmd)
{
    if (cmd->fd_input != 0) {
        if (dup2(cmd->fd_stdin, 0) == -1)
            return (perror_return("dup2"));
        close(cmd->fd_stdin);
        cmd->fd_input = 0;
    }
}

int reset_output_redirection(cmd_list_t *cmd)
{
    if (cmd->fd_output != 0) {
        if (dup2(cmd->fd_stdout, 1) == -1)
            return (perror_return("dup2"));
        close(cmd->fd_stdout);
        cmd->fd_output = 0;
    }
}