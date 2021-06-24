/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** display_prompt
*/

#include "shell42.h"

void display_prompt(head_t *head)
{
    env_list_t *user = get_var(head->env, "USER");
    env_list_t *host = get_var(head->env, "HOST");
    env_list_t *pwd = get_var(head->env, "PWD");
    int i = 0;

    if (pwd != NULL) {
        for (i = strlen(pwd->value); i >= 0 && pwd->value[i] != '/'; i--);
        i += 1;
    }
    if (isatty(0) == 1) {
        if (user != NULL && host != NULL && pwd != NULL)
            printf("[%s@%s %s]$ ", user->value, host->value, pwd->value + i);
        else
            printf("$> ");
    }
}