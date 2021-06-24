/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** print_alias
*/

#include "shell42.h"

static void print_array_alias(alias_t *alias)
{
    for (int i = 0; alias->command[i] != NULL; i++) {
        printf("%s", alias->command[i]);
        if (alias->command[i + 1] != NULL)
            printf(" ");
    }
    printf("\n");
}

void print_alias(alias_t *alias)
{
    while (alias != NULL) {
        printf("%s\t", alias->alias);
        print_array_alias(alias);
        alias = alias->next;
    }
}

void print_command_alias(alias_t *list_alias, char *alias)
{
    while (list_alias != NULL) {
        if (strcmp(list_alias->alias, alias) == 0)
            print_array_alias(list_alias);
        list_alias = list_alias->next;
    }
}