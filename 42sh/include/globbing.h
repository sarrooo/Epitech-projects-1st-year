/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** globbing
*/

#ifndef GLOBBING_H_
#define GLOBBING_H_

#include "shell42.h"

int check_globbing(head_t *head, char **cmd);
int check_no_match(head_t *head, glob_t **glob_struct,
int *i, int *nb_no_match);
int check_args_no_match(head_t *head, int nb_no_match, int nb_element);

#endif /* !GLOBBING_H_ */