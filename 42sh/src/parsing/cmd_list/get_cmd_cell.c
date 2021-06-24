/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** get_cmd_cell
*/

#include "shell42.h"

void get_redirection(cmd_list_t **cmd_list, token_list_t **token)
{
    if (*token != NULL && (*token)->token_type == REDIRECT_IN) {
        (*cmd_list)->type_input = SIMPLE_INPUT;
        get_redirection_files(token, cmd_list);
    }
    if (*token != NULL && (*token)->token_type == DOUBLE_REDIRECT_IN) {
        (*cmd_list)->type_input = DOUBLE_INPUT;
        get_redirection_files(token, cmd_list);
    }
    if (*token != NULL && (*token)->token_type == REDIRECT_OUT) {
        (*cmd_list)->type_output = SIMPLE_OUTPUT;
        get_redirection_files(token, cmd_list);
    }
    if (*token != NULL && (*token)->token_type == DOUBLE_REDIRECT_OUT) {
        (*cmd_list)->type_output = DOUBLE_OUTPUT;
        get_redirection_files(token, cmd_list);
    }
}

int get_backtick(head_t *head, cmd_list_t **cmd_list, token_list_t **token)
{
    if (*token != NULL && (*token)->token_type == BACKTICK) {
        if (head->pars_info.is_in_backtick == true) {
            head->pars_info.is_in_backtick = false;
            *token = (*token)->next;
            return 1;
        }
        else
            head->pars_info.is_in_backtick = true;
        *token = (*token)->next;
        init_args(head, token);
    }
    return 0;
}

void get_command_word(cmd_list_t **cmd, token_list_t **token, int *index_cmd)
{
    if (*token != NULL && (*token)->token_type == WORD) {
        (*cmd)->argument =
        realloc((*cmd)->argument, (*index_cmd + 1) * sizeof(char *));
        (*cmd)->argument[*index_cmd] = strdup((*token)->command);
        *index_cmd += 1;
        *token = (*token)->next;
    }
}

void get_parentheses(head_t *head, cmd_list_t **cmd,
token_list_t **token)
{
    if (*token != NULL && (*token)->token_type == LEFT_PARENTHESE) {
        head->pars_info.is_in_parentheses = true;
        (*cmd)->is_in_parentheses = true;
        (*cmd)->parentheses_status = START_PARENTHESES;
        (*cmd)->is_start_parentheses = true;
        *token = (*token)->next;
    }
    if (*token != NULL && head->pars_info.is_in_parentheses == true &&
    (*cmd)->is_in_parentheses == false) {
        (*cmd)->is_in_parentheses = true;
        (*cmd)->parentheses_status = MIDDLE_PARENTHESES;
    }
    if (*token != NULL && (*token)->token_type == RIGHT_PARENTHESE) {
        (*cmd)->parentheses_status = END_PARENTHESES;
        *token = (*token)->next;
        (*cmd)->is_end_parentheses = true;
        head->pars_info.is_in_parentheses = false;
    }
}

void get_separator_cmd(cmd_list_t **cmd, token_list_t **token)
{
    if (is_cmd_separator(*token) == true) {
        (*cmd)->type_separator = (*token)->token_type;
        *token = (*token)->next;
    }
}