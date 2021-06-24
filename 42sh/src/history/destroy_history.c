/*
** EPITECH PROJECT, 2020
** destroy_history
** File description:
** example of bad code:
*/

#include "shell42.h"

void destroy_history(history_t *list)
{
    if (list != NULL && list->next == NULL)
        free(list->cmd);
    else
        for (; list != NULL && list->next != NULL; list = list->next)
            free(list->cmd);
    free(list);
}
