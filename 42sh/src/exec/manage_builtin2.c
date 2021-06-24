/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** manage_builtin2.c
*/

#include "shell42.h"

int search_foreach_if_repeat_builtin(head_t *head, char *command, int check)
{
    if (check == 1) {
        if (strcmp(command, "foreach") == 0)
            return 1;
        else
            return 0;
    }
    if (strcmp(command, "foreach") == 0) {
        builtin_foreach(head, head->cmd_list->argument);
        return 1;
    }
    if (strcmp(command, "repeat") == 0) {
        builtin_repeat(head, head->cmd_list->argument);
        return 1;
    }
    if (strcmp(command, "if") == 0)
        return 1;
    return 0;
}