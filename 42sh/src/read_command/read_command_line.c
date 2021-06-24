/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** read_command_line
*/

#include "shell42.h"

void remove_new_line(head_t *head)
{
    int i = 0;
    char *str = head->command_line;

    for (i = 0; str[i] != '\n' && str[i] != 0; i++);
    if (str[i] != 0 && str[i + 1] != '\n')
        str[i] = '\0';
}

static int read_command_line_aux(head_t *head)
{
    stock_command(&head->cmd_history, head->command_line);
    head->command_line = check_history(&head->cmd_history, head->command_line);
    command_line_to_array(head);
    if (redirection_error_handling(head->command_array))
        return 1;
    return 0;
}

int read_command_line(head_t *head, char *arg)
{
    size_t len = 0;
    int i = 0;
    int exit_status = 0;

    if (arg == NULL) {
        if (getline(&head->command_line, &len, stdin) == -1) {
            exit_status = head->exit_status;
            destroy_head(head);
            exit(exit_status);
        }
        remove_new_line(head);
        if (read_error_handling(head->command_line))
            return 1;
        if (check_local_var(head) == -1)
            return 1;
        reformat_str(head);
    }
    else
        head->command_line = arg;
    return read_command_line_aux(head);
}