/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** pipe
*/

#ifndef PIPE_H_
#define PIPE_H_

#include "shell42.h"

void destroy_pipefd(int **pipefd);
int **init_pipefd(head_t *head);
void exec_pipe(head_t *head);
void wait_pipe_pid(head_t *head);
void stock_pipe_pid(head_t *head, pid_t pid);

#endif /* !PIPE_H_ */