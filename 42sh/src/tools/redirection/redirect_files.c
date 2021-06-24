/*
** EPITECH PROJECT, 2021
** minishell2
** File description:
** redirect_files
*/

#include "shell42.h"

int manage_redirection(head_t *head, cmd_list_t *cmd)
{
    int status = 0;

    if (manage_redirection_in(head, cmd)) {
        head->exit_status = 1;
        status = 1;
    }
    if (manage_redirection_out(head, cmd)) {
        head->exit_status = 1;
        status = 1;
    }
    return (status);
}