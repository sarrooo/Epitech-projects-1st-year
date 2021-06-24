/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** exec_parentheses
*/

#include "shell42.h"

static void skip_parentheses_command(head_t *head)
{
    cmd_list_t *temp;

    while (head->cmd_list != NULL) {
        if (head->cmd_list == NULL ||
        head->cmd_list->is_end_parentheses == true) {
            temp = head->cmd_list->next;
            destroy_cmd_element(&head->cmd_list);
            head->cmd_list = temp;
            return;
        }
        temp = head->cmd_list->next;
        destroy_cmd_element(&head->cmd_list);
        head->cmd_list = temp;
    }
    return;
}

static void exec_parentheses_fork_aux(head_t *head)
{
    int status;

    status = get_command_alias(head, head->cmd_list->argument, NULL);
    if (status != 1) {
        check_backtick_command(head);
        if (manage_redirection(head, head->cmd_list) == 0) {
            if (manage_builtin(head));
            else (manage_command(head));
        }
    }
    if (head->cmd_list->is_end_parentheses == true)
        exit(0);
    reset_input_redirection(head->cmd_list);
    reset_output_redirection(head->cmd_list);
}

static void exec_parentheses_fork(head_t *head)
{
    cmd_list_t *temp;

    while (head->cmd_list != NULL) {
        if (head->cmd_list->next != NULL &&
        head->cmd_list->next->type_separator == PIPE) {
            exec_pipe(head);
        }
        else {
            exec_parentheses_fork_aux(head);
            temp = head->cmd_list->next;
            destroy_cmd_element(&head->cmd_list);
            head->cmd_list = temp;
        }
    }
}

void exec_parentheses(head_t *head)
{
    pid_t pid = fork();
    int status;

    if (pid != 0) {
        waitpid(pid, &status, WCONTINUED);
        skip_parentheses_command(head);
    } else {
        exec_parentheses_fork(head);
    }
}