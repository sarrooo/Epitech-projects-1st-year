/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** command
*/

#ifndef COMMAND_H_
#define COMMAND_H_

#include "shell42.h"

int execute_binairy(head_t *head, cmd_list_t *cmd, env_list_t *env);
int manage_command(head_t *head);
void exec_error_message(char *str, char *message);
char *print_error_message(int status);
int binary_command(head_t *head, cmd_list_t *cmd);
char **get_path_env(head_t *head);

#endif /* !COMMAND_H_ */
