/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** create_path_env
*/

#include "shell42.h"

char **get_path_env(head_t *head)
{
    char **path;

    if (get_var(head->env, "PATH") == NULL) {
        path = malloc(sizeof(char *) * 6);
        path[0] = strdup("/usr/local/bin");
        path[1] = strdup("/usr/bin");
        path[2] = strdup("/usr/local/sbin");
        path[3] = strdup("/usr/sbin");
        path[4] = strdup("/home/epitest_docker/.dotnet/tools");
        path[5] = NULL;
    }
    else if (get_var(head->env, "PATH")->value == NULL) {
        path = malloc(sizeof(char *) * 2);
        path[0] = malloc(sizeof(char) * 4098);
        getcwd(path[0], 4097);
        path[1] = NULL;
    } else
        path = get_path_arr(head->env);
    return path;
}