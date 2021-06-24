/*
** EPITECH PROJECT, 2020
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** shell42.h
*/

#ifndef SHELL42_H
#define SHELL42_H

#define _GNU_SOURCE

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <glob.h>

typedef struct history_s history_t;
typedef struct env_list_s env_list_t;
typedef struct token_list_s token_list_t;
typedef struct alias_s alias_t;

#include "parsing.h"

typedef enum redirection_s {
    SIMPLE_INPUT,
    SIMPLE_OUTPUT,
    DOUBLE_INPUT,
    DOUBLE_OUTPUT,
    NO,
}redirection_t;

typedef enum parentheses_status_s {
    START_PARENTHESES,
    MIDDLE_PARENTHESES,
    END_PARENTHESES,
}parentheses_status_t;

typedef struct save_fd_s
{
    int in;
    int out;
}save_fd_t;

typedef struct cmd_list_s
{
    char **argument;
    redirection_t type_input;
    char *input_redirection;
    redirection_t type_output;
    char *output_redirection;
    int exec_in_background;
    int is_backtick_command;
    int is_in_parentheses;
    int is_start_parentheses;
    int is_end_parentheses;
    parentheses_status_t parentheses_status;
    token_type_t type_separator;
    save_fd_t save_fd;
    int fd_stdout;
    int fd_stdin;
    int fd_output;
    int fd_input;
    int pipefd[2];
    struct cmd_list_s *next;
}cmd_list_t;

typedef struct parsing_info_t
{
    int is_in_backtick;
    int is_in_parentheses;
}parsing_info_t;

typedef struct pipe_info_t
{
    int is_in_pipe;
    int nb_pid;
    pid_t *pid_array;
}pipe_info_t;

typedef struct head_s
{
    int exit_status;
    char *command_line;
    char **command_array;
    cmd_list_t *cmd_list;
    env_list_t *env;
    env_list_t *var;
    history_t *cmd_history;
    char *last_path;
    save_fd_t save_fd;
    parsing_info_t pars_info;
    pipe_info_t pipe_info;
    alias_t *alias;
    char *path_save;
}head_t;

// FUNCTION //
int main(int ac, char **av, char **env);
int main_shell(head_t *head);
void display_prompt(void);

// INCLUDE //
#include "read_command.h"
#include "tools.h"
#include "env.h"
#include "history.h"
#include "parsing.h"
#include "builtin.h"
#include "command.h"
#include "redirection.h"
#include "pipe.h"
#include "parentheses.h"
#include "globbing.h"
#include "alias.h"
#include "var.h"
#include "backtick.h"

#endif /* SHELL42_H */