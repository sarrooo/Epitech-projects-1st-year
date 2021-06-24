/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** create_tree
*/

#include "shell42.h"

static int error_ambigous_redirect(cmd_list_t *cmd)
{
    if (cmd->type_output != NO && cmd->next != NULL
    && cmd->next->type_separator == PIPE) {
        write(2, "Ambiguous output redirect.\n", 27);
        return 1;
    }
    if (cmd->type_input != NO && cmd->type_separator == PIPE) {
        write(2, "Ambiguous input redirect.\n", 26);
        return 1;
    }
    return 0;
}

int error_handling_redirection_pipe_aux(cmd_list_t *cmd)
{
    if (error_ambigous_redirect(cmd))
        return 1;
    if (cmd->argument[0] == NULL) {
        dprintf(2, "Invalid null command.\n");
        return -1;
    }
    if (cmd->next != NULL && cmd->next->type_separator != EMPTY) {
        if (cmd->argument[0] == NULL) {
            dprintf(2, "Invalid null command.\n");
            return 1;
        }
    }
    return 0;
}

int error_handling_redirection_pipe(cmd_list_t *cmd)
{
    if (cmd != NULL && cmd->exec_in_background == 1) {
        if (cmd->next != NULL && (cmd->next->type_separator == PIPE ||
        cmd->next->type_separator == DOUBLE_PIPE)) {
            dprintf(2, "Invalid null command.\n");
            return 1;
        }
    }
    if (cmd != NULL &&
    (cmd->type_separator == PIPE || cmd->type_separator == DOUBLE_PIPE)) {
        dprintf(2, "Invalid null command.\n");
        return 1;
    }
    while (cmd != NULL) {
        if (error_handling_redirection_pipe_aux(cmd))
            return 1;
        cmd = cmd->next;
    }
    return 0;
}

int error_handling_parentheses(token_list_t *token)
{
    while (token != NULL && token->next != NULL) {
        if (token->next->token_type == LEFT_PARENTHESE
        && is_cmd_separator(token) == false) {
            return true;
        }
        token = token->next;
    }
    return false;
}

int pars_command(head_t *head)
{
    token_list_t *token_list = NULL;
    int status = 0;

    token_list = init_token_list(head);
    init_cmd_list(head, token_list);
    destroy_token_list(token_list);
    status = error_handling_redirection_pipe(head->cmd_list);
    if (status) {
        if (head->exit_status != -1)
            head->exit_status = 1;
        return 1;
    }
    return 0;
}