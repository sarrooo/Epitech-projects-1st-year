/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** get_path
*/

#include "shell42.h"

int count_nb_path(char *path)
{
    int nb_path = 1;

    for (int i = 0; path[i] != 0; i++) {
        if (path[i] == ':')
            nb_path++;
    }
    return nb_path;
}

static char **path_to_array(env_list_t *env)
{
    int i = 0;
    int nb_path = count_nb_path(env->value);
    char **path_arr = malloc(sizeof(char *) * (nb_path + 1));
    char *path_str = strdup(env->value);
    char *temp;

    temp = strtok(path_str, ":");
    if (temp == NULL)
        return NULL;
    else
        path_arr[0] = strdup(temp);
    while (path_arr[i++] != NULL) {
        temp = strtok(NULL, ":");
        if (temp != NULL)
            path_arr[i] = strdup(temp);
        else
            path_arr[i] = NULL;
    }
    free(path_str);
    return path_arr;
}

char **get_path_arr(env_list_t *list)
{
    env_list_t *path_var = get_var(list, "PATH");
    char **path;

    if (path_var == NULL)
        return (NULL);
    path = path_to_array(path_var);
    return (path);
}