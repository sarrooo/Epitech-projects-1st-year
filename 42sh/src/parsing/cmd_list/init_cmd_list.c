/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** init_cmd_list
*/

#include "shell42.h"

cmd_list_t *init_cmd(void)
{
    cmd_list_t *cmd = malloc(sizeof(cmd_list_t));

    cmd->argument = NULL;
    cmd->type_input = NO;
    cmd->input_redirection = NULL;
    cmd->type_output = NO;
    cmd->output_redirection = NULL;
    cmd->exec_in_background = false;
    cmd->type_separator = EMPTY;
    cmd->next = NULL;
    cmd->is_in_parentheses = false;
    cmd->parentheses_status = (parentheses_status_t)NULL;
    cmd->is_backtick_command = false;
    cmd->fd_input = 0;
    cmd->fd_output = 0;
    cmd->is_start_parentheses = 0;
    cmd->is_end_parentheses = 0;
    return cmd;
}

static void close_cmd(head_t *head, cmd_list_t **cmd, int index_cmd)
{
    (*cmd)->argument =
    realloc((*cmd)->argument, (index_cmd + 1) * sizeof(char *));
    (*cmd)->argument[index_cmd] = NULL;
    add_element_cmd_list(head, (*cmd));
}

void init_args(head_t *head, token_list_t **token)
{
    int index_cmd = 0;
    cmd_list_t *cmd = init_cmd();

    if (head->pars_info.is_in_backtick == true)
        cmd->is_backtick_command = true;
    get_separator_cmd(&cmd, token);
    while (is_cmd_separator(*token) == false) {
        get_redirection(&cmd, token);
        if (get_backtick(head, &cmd, token))
            break;
        get_parentheses(head, &cmd, token);
        get_command_word(&cmd, token, &index_cmd);
        if (*token != NULL && (*token)->token_type == AND) {
            cmd->exec_in_background = true;
            *token = (*token)->next;
            break;
        }
    }
    close_cmd(head, &cmd, index_cmd);
}

void init_cmd_list(head_t *head, token_list_t *token_list)
{
    head->pars_info.is_in_parentheses = false;
    head->pars_info.is_in_backtick = false;
    head->cmd_list = NULL;
    while (token_list != NULL) {
        init_args(head, &token_list);
    }
}