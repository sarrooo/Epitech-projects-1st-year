/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** get_type_token
*/

#include "shell42.h"

static token_type_t type_token_len_1(char *cmd)
{
    switch (cmd[0]) {
    case '>':
        return REDIRECT_OUT;
    case '<':
        return REDIRECT_IN;
    case '&' :
        return AND;
    case '|' :
        return PIPE;
    case '(' :
        return LEFT_PARENTHESE;
    case ')' :
        return RIGHT_PARENTHESE;
    case '`' :
        return BACKTICK;
    case ';' :
        return SEMICOLON;
    default :
        return EMPTY;
    }
}

static token_type_t type_token_len_2(char *cmd)
{
    switch (cmd[0]) {
    case '>':
        return DOUBLE_REDIRECT_OUT;
    case '<':
        return DOUBLE_REDIRECT_IN;
    case '&' :
        return DOUBLE_AND;
    case '|' :
        return DOUBLE_PIPE;
    default :
        return EMPTY;
    }
}

token_type_t find_type_token(char *cmd)
{
    token_type_t token_type;

    if (cmd == NULL)
        return EMPTY;
    if (strlen(cmd) == 1) {
        token_type = type_token_len_1(cmd);
        if (token_type)
            return token_type;
    }
    else if (strlen(cmd) == 2) {
        token_type = type_token_len_2(cmd);
        if (token_type)
            return token_type;
    }
    return EMPTY;
}