/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** redirection
*/

#ifndef REDIRECTION_H_
#define REDIRECTION_H_

#include "shell42.h"

int manage_redirection(head_t *head, cmd_list_t *cmd);
int manage_redirection_out(head_t *head, cmd_list_t *cmd);
int manage_redirection_in(head_t *head, cmd_list_t *cmd);
int error_handling_dup_out(cmd_list_t *cmd, int fd);
int error_handling_dup_in(cmd_list_t *cmd, int fd);
int error_handling_dup_double_in(cmd_list_t *cmd);
int finish_double_input(cmd_list_t *cmd, char *temp, char *str);
int reset_input_redirection(cmd_list_t *cmd);
int reset_output_redirection(cmd_list_t *cmd);
int perror_return(char *function_name);

#endif /* !REDIRECTION_H_ */
