/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** stock_pipe_pid
*/

#include "shell42.h"

void stock_pipe_pid(head_t *head, pid_t pid)
{
    pid_t *pid_array = head->pipe_info.pid_array;

    head->pipe_info.nb_pid++;
    head->pipe_info.pid_array =
    realloc(pid_array, sizeof(pid_t) * head->pipe_info.nb_pid);
    head->pipe_info.pid_array[head->pipe_info.nb_pid - 1] = pid;
}