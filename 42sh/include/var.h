/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** var
*/

#ifndef VAR_H_
#define VAR_H_

#include "shell42.h"

int set_error_handling(char *str);
void print_var(head_t *head);
char **pars_set_var(char *str);
void destroy_var_array(char **args);
int get_var_pos(char *cmd);
char *get_name(char *cmd);
int in_dquote(char *cmd);
int check_local_var(head_t *head);
void check_indquote(char *cmd, int *i, int *k);

#endif /* !VAR_H_ */
