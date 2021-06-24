/*
** EPITECH PROJECT, 2020
** main_history
** File description:
** example of bad code:
*/

#include "shell42.h"

history_t *get_last_element_history(history_t *list)
{
    while (list->next != NULL)
        list = list->next;
    return list;
}

void stock_command(history_t **hist, char *command)
{
    history_t *new = malloc(sizeof(history_t));

    if (command[0] != '!') {
        if (command == NULL)
            new->cmd = NULL;
        else
            new->cmd = strdup(command);
        new->next = NULL;
        if (*hist != NULL)
            get_last_element_history(*hist)->next = new;
        else
            *hist = new;
    }
}