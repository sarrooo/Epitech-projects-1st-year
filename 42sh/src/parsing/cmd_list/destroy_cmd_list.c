/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** destroy_cmd_list
*/

#include "shell42.h"

void destroy_cmd_list(cmd_list_t *cmd_list)
{
    cmd_list_t *temp;

    while (cmd_list != NULL) {
        free(cmd_list->input_redirection);
        free(cmd_list->output_redirection);
        destroy_array(&cmd_list->argument);
        temp = cmd_list->next;
        free(cmd_list);
        cmd_list = temp;
    }
}