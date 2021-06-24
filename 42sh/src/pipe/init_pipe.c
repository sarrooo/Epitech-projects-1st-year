/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** init_pipe
*/

#include "shell42.h"

static int count_pipe(head_t *head, cmd_list_t *cmd)
{
    int nb_pipe = 0;

    while (cmd->next && cmd->next->type_separator == PIPE) {
        nb_pipe++;
        cmd = cmd->next;
    }
    return nb_pipe;
}

void destroy_pipefd(int **pipefd)
{
    for (int i = 0; pipefd[i] != NULL; i++)
        free(pipefd[i]);
    free(pipefd);
}

int **init_pipefd(head_t *head)
{
    int nb_pipe = count_pipe(head, head->cmd_list);
    int **pipefd = malloc(sizeof(int *) * (nb_pipe + 1));
    int i = 0;

    for (i = 0; i < nb_pipe; i++)
        pipefd[i] = malloc(sizeof(int) * 2);
    pipefd[i] = NULL;
    for (int j = 0; j < nb_pipe; j++)
        pipe(pipefd[j]);
    return (pipefd);
}