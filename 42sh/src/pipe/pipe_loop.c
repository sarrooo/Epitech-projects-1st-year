/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** pipe_loop
*/

#include "shell42.h"

static void manage_last_pipe(head_t *head, int **pipefd, int i)
{
    if (head->save_fd.in == -1)
        head->save_fd.in = dup(0);
    dup2(pipefd[i - 1][0], 0);
    close(pipefd[i - 1][0]);
    dup2(head->save_fd.out, 1);
    close(head->save_fd.out);
    head->save_fd.out = -1;
}

void manage_pipe_output_and_input(head_t *head, int **pipefd, int i)
{
    if (i == 0) {
        head->save_fd.out = dup(1);
        dup2(pipefd[i][1], 1);
        close(pipefd[i][1]);
    }
    if (pipefd[i] == NULL) {
        manage_last_pipe(head, pipefd, i);
    }
    if (i != 0 && pipefd[i] != NULL) {
        if (head->save_fd.in == -1)
            head->save_fd.in = dup(0);
        dup2(pipefd[i - 1][0], 0);
        close(pipefd[i - 1][0]);
        dup2(pipefd[i][1], 1);
        close(pipefd[i][1]);
    }
}

static int pipe_sequence_ended(head_t *head, int i)
{
    if (head->cmd_list != NULL) {
        if (head->cmd_list->type_separator == PIPE)
            return false;
        if (i != 0 && head->cmd_list->type_separator != PIPE)
            return true;
    }
    if (head->cmd_list != NULL && head->cmd_list->next != NULL) {
        if (head->cmd_list->next->type_separator == PIPE)
            return false;
    }
    return true;
}

static int exec_pipe_command(head_t *head, int **pipefd, int i)
{
    cmd_list_t *temp;

    check_backtick_command(head);
    manage_pipe_output_and_input(head, pipefd, i);
    if (get_command_alias(head, head->cmd_list->argument, NULL) != 1) {
        if (manage_redirection(head, head->cmd_list) == 0) {
            if (manage_builtin_pipe(head));
            else (manage_command(head));
        }
    }
    reset_input_redirection(head->cmd_list);
    reset_output_redirection(head->cmd_list);
    temp = head->cmd_list->next;
    destroy_cmd_element(&head->cmd_list);
    head->cmd_list = temp;
}

void exec_pipe(head_t *head)
{
    int **pipefd = init_pipefd(head);

    head->pipe_info.is_in_pipe = 1;
    for (int i = 0; pipe_sequence_ended(head, i) == false; i++) {
        exec_pipe_command(head, pipefd, i);
    }
    dup2(head->save_fd.in, 0);
    close(head->save_fd.in);
    head->save_fd.in = -1;
    wait_pipe_pid(head);
    destroy_pipefd(pipefd);
}