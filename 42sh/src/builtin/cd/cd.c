/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** cd
*/

#include "shell42.h"

int check_cd_error(head_t *head, char **args)
{
    struct stat *info_path = malloc(sizeof(struct stat));

    if (access(args[1], F_OK) == -1) {
        exec_error_message(args[1], ": No such file or directory.\n");
        head->exit_status = 1;
        if (head->pipe_info.is_in_pipe == true)
            exit(1);
        free(info_path);
        return 1;
    }
    stat(args[1], info_path);
    if (!(S_ISDIR(info_path->st_mode))) {
        exec_error_message(args[1], ": Not a directory.\n");
        head->exit_status = 1;
        if (head->pipe_info.is_in_pipe == true)
            exit(1);
        free(info_path);
        return 1;
    }
    free(info_path);
    return 0;
}

static void get_home_path(head_t *head, char ***cmd)
{
    env_list_t *home_env = get_var(head->env, "HOME");

    *cmd = realloc((*cmd), sizeof(char *) * 3);
    if (home_env == NULL) {
        (*cmd)[1] = malloc(sizeof(char) * 2);
        (*cmd)[1][0] = '/';
        (*cmd)[1][1] = 0;
    }
    else
        (*cmd)[1] = strdup(home_env->value);
    (*cmd)[2] = NULL;
}

int check_args_cd(head_t *head, char ***cmd)
{
    if ((*cmd)[1] == NULL) {
        get_home_path(head, cmd);
    }
    if (strcmp((*cmd)[1], "-") == 0) {
        if (head->last_path != NULL) {
            (*cmd) = realloc(*cmd, sizeof(char *) * 3);
            (*cmd)[1] = strdup(head->last_path);
            (*cmd)[2] = NULL;
        }
        else {
            check_args_aux(head);
        }
    }
    return 0;
}

void set_pwd_env(head_t *head, char *new_path, char **new_args)
{
    env_list_t *env_list = get_var(head->env, "PWD");

    if (getcwd(new_path, 4097) != NULL);
    else {
        free(new_path);
        new_path = NULL;
    }
    new_args[2] = new_path;
    if (env_list == NULL) {
        add_element_env("PWD", new_path, &head->env);
    }
    else {
        if (env_list->value != NULL)
            free(env_list->value);
        if (new_path != NULL)
            env_list->value = strdup(new_path);
        else
            env_list->value = NULL;
    }
    free(new_path);
}

void builtin_cd(head_t *head, char ***cmd)
{
    char *new_args[4] = {"setenv", "PWD", NULL, NULL};
    char *new_path;

    if (cd_error_handling(head, cmd))
        return;
    if (check_args_cd(head, cmd))
        return;
    if (check_cd_error(head, *cmd))
        return;
    new_path = malloc(sizeof(char) * 4098);
    if (getcwd(new_path, 4097) != NULL) {
        if (head->last_path != NULL)
            free(head->last_path);
        head->last_path = strdup(new_path);
    }
    chdir((*cmd)[1]);
    set_pwd_env(head, new_path, new_args);
    if (head->pipe_info.is_in_pipe == true)
        exit(0);
    head->exit_status = 0;
}