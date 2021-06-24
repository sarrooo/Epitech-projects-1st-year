/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** linked_list
*/

#include "shell42.h"

int count_env_var(env_list_t *env)
{
    int nb_var = 0;

    while (env != NULL) {
        nb_var++;
        env = env->next;
    }
    return (nb_var + 1);
}

char **env_list_to_array(env_list_t *ev)
{
    int i = 0;
    int nb_var = count_env_var(ev);
    char **env_array = malloc(sizeof(char *) * nb_var);

    for (i = 0; ev != NULL; i++) {
        if (ev->value != NULL)
            env_array[i] =
            malloc(sizeof(char) * (strlen(ev->name) + strlen(ev->value) + 2));
        else
            env_array[i] =
            malloc(sizeof(char) * (strlen(ev->name) + 2));
        env_array[i][0] = 0;
        env_array[i] = strcat(env_array[i], ev->name);
        env_array[i] = strcat(env_array[i], "=");
        if (ev->value != NULL)
            env_array[i] = strcat(env_array[i], ev->value);
        ev = ev->next;
    }
    env_array[i] = NULL;
    return (env_array);
}

env_list_t *get_last_element_env(env_list_t *list)
{
    while (list->next != NULL)
        list = list->next;
    return list;
}

void destroy_env_list(env_list_t **list)
{
    env_list_t *tmp;

    while (*list != NULL) {
        free((*list)->name);
        free((*list)->value);
        tmp = (*list)->next;
        free(*list);
        *list = tmp;
    }
    *list = NULL;
}

void add_element_env(char *name, char *value, env_list_t **list)
{
    env_list_t *new_element = malloc(sizeof(env_list_t));

    if (name == NULL)
        new_element->name = NULL;
    else
        new_element->name = strdup(name);
    if (value == NULL)
        new_element->value = NULL;
    else
        new_element->value = strdup(value);
    new_element->next = NULL;
    if (*list != NULL)
        get_last_element_env(*list)->next = new_element;
    else
        *list = new_element;
}