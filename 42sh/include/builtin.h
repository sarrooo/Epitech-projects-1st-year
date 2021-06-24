/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** builtin
*/

#ifndef BUILTIN_H_
#define BUILTIN_H_

#include "shell42.h"

int manage_builtin(head_t *head);
int manage_builtin_pipe(head_t *head);
int search_alias_builtin(head_t *head, char *command);
int search_where_wich_builtin(head_t *head, char *command);
int search_env_builtin(head_t *head, char *command);
int search_cd_exit_builtin(head_t *head, char *command);
void check_args_aux(head_t *head);

void builtin_env(head_t *head, char **cmd);
void builtin_setenv(head_t *head, char **cmd);
void builtin_unsetenv(head_t *head, char **cmd);
void builtin_exit(head_t *head, char **cmd);

// CD //
void builtin_cd(head_t *head, char ***cmd);
int cd_error_handling(head_t *head, char ***cmd);

// CMD //
cmd_list_t *new_element(cmd_list_t *cmd_l, char **new);
cmd_list_t *insert_element(cmd_list_t *cmd_l, char **new);

// parsing array //
char **str_to_2d(char *str);

void builtin_where(head_t *head, char **cmd);
void builtin_which(head_t *head, char **cmd);
void builtin_foreach(head_t *head, char **cmd);
void builtin_set(head_t *head, char **cmd);
void builtin_unset(head_t *head, char **cmd);
void builtin_unalias(head_t *head, char **cmd);
void builtin_alias(head_t *head, char **cmd);
void builtin_repeat(head_t *head, char **cmd);
int exec_command_line(head_t *head);
int search_foreach_if_repeat_builtin(head_t *head, char *command, int check);

#endif /* !BUILTIN_H_ */