/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** alias
*/

#ifndef ALIAS_H_
#define ALIAS_H_

#include "shell42.h"

typedef struct alias_s
{
    char *alias;
    char **command;
    struct alias_s *next;
}alias_t;

int get_command_alias(head_t *head, char **cmd, char *previous);

// PRINT //
void print_alias(alias_t *alias);
void print_command_alias(alias_t *list_alias, char *alias);

// TOOLS //
void destroy_alias(alias_t *alias);
alias_t *get_last_alias(alias_t *alias);
int repars_command(head_t *head, char **alias_command);

#endif /* !ALIAS_H_ */