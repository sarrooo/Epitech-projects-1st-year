/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** error_handling
*/

#include "shell42.h"

void check_args_aux(head_t *head)
{
    dprintf(2, ": No such file or directory.\n");
    if (head->pipe_info.is_in_pipe == true)
        exit(1);
}

int cd_error_handling(head_t *head, char ***cmd)
{
    if (count_nb_element_array(*cmd) > 2) {
        write(2, "cd: Too many arguments.\n", 24);
        head->exit_status = 1;
        if (head->pipe_info.is_in_pipe == true)
            exit(1);
        return 1;
    }
    if ((*cmd)[1] != NULL && strcmp((*cmd)[1], "*") == 0) {
        dprintf(2, "*: Ambiguous.\n");
        head->exit_status = 1;
        if (head->pipe_info.is_in_pipe == true)
            exit(1);
        return 1;
    }
    return 0;
}