/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** wait_pipe_pid
*/

#include "shell42.h"

static void get_pipe_exit_status(head_t *head, int status)
{
    if (WIFSIGNALED(status)) {
        print_error_message(status);
        head->exit_status = WTERMSIG(status) + 128;
    }
    else {
        head->exit_status = WEXITSTATUS(status);
    }
}

static int check_if_pid_ended(head_t *head, int i, int nb_pid_remain)
{
    int status;

    if (head->pipe_info.pid_array[i] != -1) {
        if (waitpid(head->pipe_info.pid_array[i], &status, WNOHANG) != 0) {
            nb_pid_remain--;
            head->pipe_info.pid_array[i] = -1;
            get_pipe_exit_status(head, status);
        }
    }
    return nb_pid_remain;
}

void wait_pipe_pid(head_t *head)
{
    int nb_pid_remain = head->pipe_info.nb_pid;

    while (nb_pid_remain > 0) {
        for (int i = 0; i < head->pipe_info.nb_pid; i++) {
            nb_pid_remain = check_if_pid_ended(head, i, nb_pid_remain);
        }
    }
    head->pipe_info.is_in_pipe = 0;
    head->pipe_info.nb_pid = 0;
    free(head->pipe_info.pid_array);
    head->pipe_info.pid_array = NULL;
}