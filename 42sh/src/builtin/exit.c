/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** exit
*/

#include "shell42.h"

void builtin_exit(head_t *head, char **cmd)
{
    int nb_var = count_nb_element_array(cmd);

    if (nb_var > 2) {
        write(2, "exit: Expression Syntax.\n", 25);
        head->exit_status = 1;
        if (head->pipe_info.is_in_pipe == true)
            exit(1);
        return;
    }
    if (isatty(0) == 1)
        printf("exit\n");
    if (nb_var == 1) {
        exit(head->exit_status);
    }
    else {
        exit(atoi(cmd[1]));
    }
}