/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** tools
*/

#include "shell42.h"

void destroy_cmd_element(cmd_list_t **element)
{
    destroy_array(&(*element)->argument);
    if ((*element)->input_redirection)
        free((*element)->input_redirection);
    if ((*element)->output_redirection)
        free((*element)->output_redirection);
    free((*element));
    *element = NULL;
}

void print_cmd(cmd_list_t *cmd_list)
{
    while (cmd_list != NULL) {
        printf("command->\n");
        print_array(cmd_list->argument);
        printf("------\n");
        printf("Type_input-> %d\n", cmd_list->type_input);
        printf("Redirection_input-> %s\n", cmd_list->input_redirection);
        printf("Type_output-> %d\n", cmd_list->type_output);
        printf("Redirection_output-> %s\n", cmd_list->output_redirection);
        printf("Separator-> %d\n", cmd_list->type_separator);
        printf("Exec_background-> %d\n", cmd_list->exec_in_background);
        printf("Parentheses-> %d\n", cmd_list->is_in_parentheses);
        printf("Parentheses_status-> %d\n", cmd_list->parentheses_status);
        printf("Parentheses_start-> %d\n", cmd_list->is_start_parentheses);
        printf("Parentheses_end-> %d\n", cmd_list->is_end_parentheses);
        printf("Parentheses_status-> %d\n", cmd_list->parentheses_status);
        printf("Backtick_status-> %d\n", cmd_list->is_backtick_command);
        printf("\n");
        cmd_list = cmd_list->next;
    }
}

int is_cmd_separator(token_list_t *current_token)
{
    if (current_token == NULL)
        return true;
    switch (current_token->token_type) {
    case PIPE:
        return true;
    case DOUBLE_PIPE:
        return true;
    case AND:
        return true;
    case DOUBLE_AND:
        return true;
    case SEMICOLON:
        return true;
    default:
        return false;
    }
}

void add_element_cmd_list(head_t *head, cmd_list_t *cmd)
{
    cmd_list_t *first = head->cmd_list;

    if (first == NULL) {
        head->cmd_list = cmd;
        return;
    }
    while (first->next != NULL)
        first = first->next;
    first->next = cmd;
}

void get_redirection_files(token_list_t **token, cmd_list_t **cmd_list)
{
    if ((*cmd_list)->type_input != NO) {
        *token = (*token)->next;
        (*cmd_list)->input_redirection = strdup((*token)->command);
        *token = (*token)->next;
    }
    else {
        *token = (*token)->next;
        (*cmd_list)->output_redirection = strdup((*token)->command);
        *token = (*token)->next;
    }
}