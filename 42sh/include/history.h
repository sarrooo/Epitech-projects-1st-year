/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** env
*/

#ifndef HISTORY_H_
#define HISTORY_H_

#include "shell42.h"

// STRUCTURE //
typedef struct history_s
{
    char *cmd;
    struct history_s *next;
}history_t;

// FUNCTION //

void stock_command(history_t **hist, char *command);
void destroy_history(history_t *list);
char *check_history(history_t **hist, char *command);
char *get_hist(char *str, int i);
int my_cmp(char *stra, char *strb);
char *delete_point(char *command, int i);

#endif /* !HISTORY_H_ */