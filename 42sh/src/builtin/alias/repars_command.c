/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** repars_command
*/

#include "shell42.h"

int error_handling_redirection_pipe(cmd_list_t *cmd);
int error_handling_parentheses(token_list_t *token);

static void set_cmd_line_alias(head_t *head, char **alias_command)
{
    char *new_cmd = strdup(alias_command[0]);

    for (int i = 1; alias_command[i] != 0; i++) {
        new_cmd = realloc(new_cmd, sizeof(char) * (strlen(new_cmd) + 2));
        new_cmd = strcat(new_cmd, " ");
        new_cmd = realloc(new_cmd, sizeof(char) *
        (strlen(new_cmd) + strlen(alias_command[i] + 1)));
        new_cmd = strcat(new_cmd, strdup(alias_command[i]));
    }
    destroy_array(&alias_command);
    for (int i = 1; head->cmd_list->argument[i] != 0; i++) {
        new_cmd = realloc(new_cmd, sizeof(char) * (strlen(new_cmd) + 2));
        new_cmd = strcat(new_cmd, " ");
        new_cmd = realloc(new_cmd, sizeof(char) *
        (strlen(new_cmd) + strlen(head->cmd_list->argument[i]) + 1));
        new_cmd = strcat(new_cmd, head->cmd_list->argument[i]);
    }
    free(head->command_line);
    head->command_line = new_cmd;
    reformat_str(head);
}

static int set_cmd_array_alias(head_t *head, char **alias_cmd)
{
    destroy_array(&head->command_array);
    if (head->cmd_list->argument != NULL)
        destroy_array(&head->cmd_list->argument);
    command_line_to_array(head);
    if (redirection_error_handling(head->command_array))
        return 1;
    return 0;
}

static void init_cmd_list_alias(head_t *head, token_list_t *token_list)
{
    while (token_list != NULL)
        init_args(head, &token_list);
}

static int set_cmd_list_alias(head_t *head)
{
    token_list_t *token_list = NULL;
    cmd_list_t *save_cmd_list = head->cmd_list->next;

    free(head->cmd_list->input_redirection);
    free(head->cmd_list->output_redirection);
    free(head->cmd_list);
    head->cmd_list = NULL;
    token_list = init_token_list(head);
    head->pars_info.is_in_parentheses = false;
    head->pars_info.is_in_backtick = false;
    init_cmd_list_alias(head, token_list);
    destroy_token_list(token_list);
    return 0;
}

int repars_command(head_t *head, char **alias_command)
{
    cmd_list_t *save_cmd_list = head->cmd_list->next;
    cmd_list_t *first;

    set_cmd_line_alias(head, alias_command);
    if (set_cmd_array_alias(head, alias_command))
        return 1;
    set_cmd_list_alias(head);
    if (error_handling_redirection_pipe(head->cmd_list)) {
        if (head->exit_status != -1)
            head->exit_status = 1;
        return 1;
    }
    first = head->cmd_list;
    while (first->next != NULL)
        first = first->next;
    first->next = save_cmd_list;
}