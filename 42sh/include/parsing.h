/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** parsing
*/

#ifndef PARSING_H_
#define PARSING_H_

#include "shell42.h"

typedef struct head_s head_t;
typedef struct cmd_list_s cmd_list_t;

typedef enum token_type_s {
    WORD,
    REDIRECT_IN,
    DOUBLE_REDIRECT_IN,
    REDIRECT_OUT,
    DOUBLE_REDIRECT_OUT,
    PIPE,
    DOUBLE_AND,
    DOUBLE_PIPE,
    AND,
    SEMICOLON,
    LEFT_PARENTHESE,
    RIGHT_PARENTHESE,
    BACKTICK,
    EMPTY,
}token_type_t;

typedef struct token_list_s
{
    token_type_t token_type;
    char *command;
    token_list_t *next;
}token_list_t;

int pars_command(head_t *head);

// INIT //
void init_cmd_list(head_t *head, token_list_t *token_list);
void init_args(head_t *head, token_list_t **token);

// TOOLS //
void get_redirection_files(token_list_t **token, cmd_list_t **cmd_list);
void add_element_cmd_list(head_t *head, cmd_list_t *cmd);
int is_cmd_separator(token_list_t *current_token);
void print_cmd(cmd_list_t *cmd_list);
void destroy_cmd_element(cmd_list_t **element);
void destroy_cmd_list(cmd_list_t *cmd_list);

// GET CMD CELL //
void get_parentheses(head_t *head, cmd_list_t **cmd,
token_list_t **token);
void get_separator_cmd(cmd_list_t **cmd, token_list_t **token);
void get_command_word(cmd_list_t **cmd, token_list_t **token, int *index_cmd);
int get_backtick(head_t *head, cmd_list_t **cmd_list, token_list_t **token);
void get_redirection(cmd_list_t **cmd_list, token_list_t **token);

// TOKEN //
token_list_t *init_token_list(head_t *head);
void destroy_token_list(token_list_t *token_list);
token_type_t find_type_token(char *cmd);

#endif /* !TREE_H_ */
