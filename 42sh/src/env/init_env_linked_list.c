/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** init_env_linked_list
*/

#include "shell42.h"

static char *get_env_name(char *str)
{
    char *name = malloc(sizeof(char) * strlen(str));
    int i = 0;

    for (i = 0; str[i] != 0 && str[i] != '='; i++) {
        name[i] = str[i];
    }
    name[i] = 0;
    return name;
}

static char *get_env_value(char *str)
{
    char *value = malloc(sizeof(char) * strlen(str));
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != 0 && str[i] != '='; i++);
    if (str[i] == 0 || str[i + 1] == 0)
        return NULL;
    i++;
    for (i; str[i] != 0; i++) {
        value[j] = str[i];
        j++;
    }
    if (j == 0)
        return NULL;
    value[j] = 0;
    return value;
}

void init_env_linked_list(head_t *head, char **env)
{
    char *name;
    char *value;

    for (int i = 0; env[i] != NULL; i++) {
        name = get_env_name(env[i]);
        value = get_env_value(env[i]);
        add_element_env(name, value, &head->env);
        free(name);
        free(value);
    }
}