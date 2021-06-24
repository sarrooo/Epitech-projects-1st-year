/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** redirect_file_in_aux
*/

#include "shell42.h"

int finish_double_input(cmd_list_t *cmd, char *temp, char *str)
{
    if (temp != NULL)
        free(temp);
    if (pipe(cmd->pipefd) == -1)
        return (perror_return("pipe"));
    write(cmd->pipefd[1], str, strlen(str));
    if (error_handling_dup_double_in(cmd))
        return (1);
    return (0);
}