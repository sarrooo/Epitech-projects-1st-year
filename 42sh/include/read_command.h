/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** read_command
*/

#ifndef READ_COMMAND_H_
#define READ_COMMAND_H_

#include "shell42.h"

// FUNCTION //
int read_command_line(head_t *head, char *arg);

// REFORMAT STRING //
int count_extra_space(char *line);
void add_space_separator(char *str, char *new_str, int i, int *index_new);
void reformat_str(head_t *head);
void command_line_to_array(head_t *head);
void between_quote(char *str, char *str_clean, int *i, int *index_str_clean);
void between_simple_quote(char *str, char *str_clean,
int *i, int *index_str_clean);
void between_backtick(char *str, char *str_clean,
int *i, int *index_str_clean);

// ERROR HANDLING //
int read_error_handling(char *str);
int redirection_error_handling(char **array);
int redirection_error_handling(char **array);

#endif /* !READ_COMMAND_H_ */