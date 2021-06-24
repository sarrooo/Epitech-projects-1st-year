/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** tools_alias
*/

#include "shell42.h"

alias_t *get_last_alias(alias_t *alias)
{
    while (alias->next != NULL)
        alias = alias->next;
    return (alias);
}

void destroy_alias(alias_t *alias)
{
    alias_t *temp;

    while (alias != NULL) {
        free(alias->alias);
        destroy_array(&alias->command);
        temp = alias->next;
        free(alias);
        alias = temp;
    }
}