/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** main_shell
*/

#include "shell42.h"

static void exec_command(head_t *head)
{
    int status;

    check_backtick_command(head);
    if (manage_redirection(head, head->cmd_list) == 0) {
        if (manage_builtin(head));
        else (manage_command(head));
    }
    reset_input_redirection(head->cmd_list);
    reset_output_redirection(head->cmd_list);
}

static void command_loop(head_t *head)
{
    cmd_list_t *temp;
    int status = 0;

    status = get_command_alias(head, head->cmd_list->argument, NULL);
    if (strcmp(head->cmd_list->argument[0], "foreach") != 0 &&
    head->cmd_list->is_start_parentheses == 1) {
        exec_parentheses(head);
    }
    else if (head->cmd_list != NULL && head->cmd_list->next != NULL &&
    head->cmd_list->next->type_separator == PIPE) {
        exec_pipe(head);
    } else {
        if (status == 0)
            exec_command(head);
        temp = head->cmd_list->next;
        destroy_cmd_element(&head->cmd_list);
        head->cmd_list = temp;
    }
}

int exec_command_line(head_t *head)
{
    while (head->cmd_list != NULL) {
        command_loop(head);
    }
}

static int reset_command_line(head_t *head)
{
    destroy_array(&head->command_array);
    if (head->command_line != NULL && head->command_line[0] != '\0')
        free(head->command_line);
}

int main_shell(head_t *head)
{
    while (1) {
        display_prompt();
        if (read_command_line(head, NULL) == 1)
            head->exit_status = 1;
        else if (pars_command(head) == 0) {
            exec_command_line(head);
        }
        reset_command_line(head);
    }
}