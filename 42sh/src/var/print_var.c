/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** print_var
*/

#include "shell42.h"

static char *get_last_history_set(history_t *history)
{
    while (history->next->next != NULL)
        history = history->next;
    return history->cmd;
}

void print_var(head_t *head)
{
    env_list_t *var = head->var;

    if (head->cmd_history == NULL || head->cmd_history->next == NULL)
        printf("_\n");
    else
        printf("_\t%s\n\n", get_last_history_set(head->cmd_history));
    while (var != NULL) {
        printf("%s\t%s\n", var->name, var->value);
        var = var->next;
    }
}