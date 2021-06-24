/*
** EPITECH PROJECT, 2020
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** main.c
*/

#include "shell42.h"

void init_head(head_t *head, char **env)
{
    head->exit_status = 0;
    head->command_array = NULL;
    head->command_line = NULL;
    head->env = NULL;
    head->cmd_history = NULL;
    head->last_path = NULL;
    head->cmd_list = NULL;
    head->save_fd.in = -1;
    head->save_fd.out = -1;
    head->pipe_info.is_in_pipe = 0;
    head->pipe_info.pid_array = NULL;
    head->pipe_info.nb_pid = 0;
    head->alias = NULL;
    head->var = NULL;
    init_env_linked_list(head, env);
}

void destroy_head(head_t *head)
{
    if (head->command_array != NULL)
        destroy_array(&head->command_array);
    if (head->command_line != NULL && head->command_line[0] != '\0')
        free(head->command_line);
    if (head->cmd_list != NULL)
        destroy_cmd_list(head->cmd_list);
    head->command_line = NULL;
    destroy_env_list(&head->env);
    destroy_env_list(&head->var);
    destroy_history(head->cmd_history);
    destroy_alias(head->alias);
    free(head->last_path);
    free(head);
}

int main(int ac, char **av, char **env)
{
    head_t *head = malloc(sizeof(head_t));
    int exit_status;

    if (ac != 1)
        return (84);
    init_head(head, env);
    main_shell(head);
    exit_status = head->exit_status;
    destroy_head(head);
    return (exit_status);
}