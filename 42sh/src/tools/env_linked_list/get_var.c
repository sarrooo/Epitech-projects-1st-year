/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** get_index_var
*/

#include "shell42.h"

env_list_t *get_var(env_list_t *list, char *name)
{
    env_list_t *temp = list;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0)
            return (temp);
        temp = temp->next;
    }
    return (NULL);
}