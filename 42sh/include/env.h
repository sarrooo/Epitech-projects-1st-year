/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** env
*/

#ifndef ENV_H_
#define ENV_H_

#include "shell42.h"

// STRUCTURE //
typedef struct env_list_s
{
    char *name;
    char *value;
    struct env_list_s *next;
}env_list_t;

// FUNCTION //
void init_env_linked_list(head_t *head, char **env);

#endif /* !ENV_H_ */