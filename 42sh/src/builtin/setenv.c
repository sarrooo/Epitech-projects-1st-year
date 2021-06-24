/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** setenv
*/

#include "shell42.h"

static int check_non_alpha(char letter)
{
    int ok = 0;

    if (!(letter > 64 && letter < 91))
        ok = 1;
    if (ok == 1 && letter > 96 && letter < 123)
        ok = 0;
    if (ok == 1 && letter > 47 && letter < 58)
        ok = 0;
    if (ok == 1 && letter == '.')
        ok = 0;
    if (ok == 1) {
        dprintf(2,
        "setenv: Variable name must contain alphanumeric characters.\n");
        return 1;
    }
    return 0;
}

static int setenv_error_handling(char **args)
{
    int ok = 0;
    int i = 0;

    if (!(args[1][0] > 64 && args[1][0] < 91))
        ok = 1;
    if (ok == 1 && args[1][0] > 96 && args[1][0] < 123)
        ok = 0;
    if (ok == 0) {
        for (i = 0; args[1][i] != 0 && args[1][i] != 32; i++);
        if (i != strlen(args[1]))
            ok = 1;
    }
    if (ok == 1) {
        dprintf(2, "setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    for (int i = 0; args[1][i] != '\0'; i++) {
        if (check_non_alpha(args[1][i]) == 1)
            return 1;
    }
    return 0;
}

void exec_setenv(head_t *head, char **cmd)
{
    int nb_var;
    env_list_t *env_list = get_var(head->env, cmd[1]);
    int i;

    if (env_list == NULL) {
        add_element_env(cmd[1], cmd[2], &head->env);
    }
    else {
        if (env_list->value != NULL)
            free(env_list->value);
        if (cmd[2] != NULL)
            env_list->value = strdup(cmd[2]);
        else
            env_list->value = NULL;
    }
    if (head->pipe_info.is_in_pipe == true)
        exit(0);
    head->exit_status = 0;
}

void builtin_setenv(head_t *head, char **cmd)
{
    int nb_args = count_nb_element_array(cmd);
    char *new_args[2] = {"env", NULL};

    if (nb_args == 1) {
        builtin_env(head, new_args);
        return;
    }
    if (nb_args > 3) {
        head->exit_status = 1;
        write(2, "setenv: Too many arguments.\n", 28);
        if (head->pipe_info.is_in_pipe == true)
            exit(1);
        return;
    }
    if (setenv_error_handling(cmd) == true) {
        head->exit_status = 1;
        if (head->pipe_info.is_in_pipe == true)
            exit(1);
        return;
    }
    exec_setenv(head, cmd);
}