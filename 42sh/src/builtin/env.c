/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** env
*/

#include "shell42.h"

void builtin_env(head_t *head, char **cmd)
{
    env_list_t *list = head->env;

    if (count_nb_element_array(cmd) != 1) {
        write(2, "env: Too many arguments.\n", 25);
        head->exit_status = 1;
        if (head->pipe_info.is_in_pipe == true)
            exit(1);
        return;
    }
    while (list != NULL) {
        dprintf(1, "%s=", list->name);
        if (list->value != NULL)
            dprintf(1, "%s\n", list->value);
        else
            dprintf(1, "\n", list->value);
        list = list->next;
    }
    if (head->pipe_info.is_in_pipe == true)
        exit(0);
    head->exit_status = 0;
}