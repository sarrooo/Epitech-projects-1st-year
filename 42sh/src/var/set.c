/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** set
*/

#include "shell42.h"

void destroy_var_array(char **args)
{
    free(args[0]);
    if (args[1] != NULL)
        free(args[1]);
    free(args);
}

char **pars_set_var(char *str)
{
    char **var_array = malloc(sizeof(char *) * 2);
    int i = 0;

    var_array[0] = malloc(sizeof(char));
    for (i = 0; str[i] != 0 && str[i] != '='; i++) {
        var_array[0] = realloc(var_array[0], sizeof(char) * (i + 1));
        var_array[0][i] = str[i];
    }
    var_array[0] = realloc(var_array[0], sizeof(char) * (i + 1));
    var_array[0][i] = 0;
    if (str[i] == 0 || str[i + 1] == 0) {
        var_array[1] = NULL;
        return var_array;
    }
    var_array[1] = strdup(str + i + 1);
    return var_array;
}

void exec_set(head_t *head, char *str)
{
    char **cmd = pars_set_var(str);
    env_list_t *env_list = get_var(head->var, cmd[0]);

    if (env_list == NULL)
        add_element_env(cmd[0], cmd[1], &head->var);
    else {
        if (env_list->value != NULL)
            free(env_list->value);
        if (cmd[1] != NULL)
            env_list->value = strdup(cmd[1]);
        else
            env_list->value = NULL;
    }
    destroy_var_array(cmd);
    head->exit_status = 0;
    if (head->pipe_info.is_in_pipe == true)
        exit(0);
}

static void check_set(head_t *head, char **cmd, int i)
{
    if (set_error_handling(cmd[i]) == true) {
        head->exit_status = 1;
        if (head->pipe_info.is_in_pipe == true)
            exit(1);
    }
    else
        exec_set(head, cmd[i]);
}

void builtin_set(head_t *head, char **cmd)
{
    int nb_args = count_nb_element_array(cmd);

    if (nb_args == 1) {
        print_var(head);
        return;
    }
    for (int i = 1; cmd[i] != NULL; i++)
        check_set(head, cmd, i);
}