/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** foreach
*/

#include "shell42.h"

cmd_list_t *insert_element(cmd_list_t *cmd_l, char **new)
{
    cmd_list_t *back = cmd_l;
    cmd_list_t *element = malloc(sizeof(cmd_list_t));

    element->argument = new;
    element->input_redirection = back->input_redirection;
    element->output_redirection = back->output_redirection;
    element->exec_in_background = back->exec_in_background;
    element->is_backtick_command = back->is_backtick_command;
    element->is_in_parentheses = back->is_in_parentheses;
    element->is_start_parentheses = back->is_start_parentheses;
    element->is_end_parentheses = back->is_end_parentheses;
    element->fd_stdout = back->fd_stdout;
    element->fd_stdin = back->fd_stdin;
    element->fd_output = back->fd_output;
    element->fd_input = back->fd_input;
    element->pipefd[2] = back->pipefd[2];
    element->next = back->next;
    back->next = element;
    back = cmd_l;
    return (back);
}

cmd_list_t *new_element(cmd_list_t *cmd_l, char **new)
{
    cmd_list_t *back = cmd_l;
    cmd_list_t *element = malloc(sizeof(cmd_list_t));

    element->argument = new;
    element->input_redirection = back->input_redirection;
    element->output_redirection = back->output_redirection;
    element->exec_in_background = back->exec_in_background;
    element->is_backtick_command = back->is_backtick_command;
    element->is_start_parentheses = back->is_start_parentheses;
    element->is_end_parentheses = back->is_end_parentheses;
    element->fd_stdout = back->fd_stdout;
    element->fd_stdin = back->fd_stdin;
    element->fd_output = back->fd_output;
    element->fd_input = back->fd_input;
    element->pipefd[2] = back->pipefd[2];
    element->next = NULL;
    while (back->next != NULL)
        back = back->next;
    back->next = element;
    back = cmd_l;
    return (cmd_l);
}

char **arraydup(char **array)
{
    int size = 0;
    char **new;

    for (; array[size] != NULL; size++);
    new = malloc(sizeof(char *) * (size * 2));
    for (int x = 0; x < size; x++) {
        new[x] = strdup(array[x]);
    }
    new[size] = NULL;
    return (new);
}

char **rm_begin(char **array)
{
    int begin = 0;

    for (int x = 2; array[x] != NULL; x++) {
        array[begin++] = array[x];
    }
    array[begin] = NULL;
    return (array);
}

void builtin_repeat(head_t *head, char **cmd)
{
    int size = atoi(cmd[1]);
    cmd_list_t *cmd_l = head->cmd_list;

    cmd_l->argument = rm_begin(cmd_l->argument);
    for (int x = 0; x < size; x++) {
        if (cmd_l->next == NULL)
            cmd_l = new_element(cmd_l, arraydup(cmd));
        else
            cmd_l = insert_element(cmd_l, arraydup(cmd));
    }
}