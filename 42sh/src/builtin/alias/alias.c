/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** alias
*/

#include "shell42.h"

int get_command_alias(head_t *head, char **cmd, char *previous)
{
    alias_t *alias = head->alias;
    char **temp;

    while (alias != NULL) {
        if (strcmp(alias->alias, cmd[0]) == 0) {
            if (previous != NULL && strcmp(previous, alias->command[0]) == 0) {
                dprintf(2, "Alias loop.\n");
                head->exit_status = 1;
                return 1;
            }
            temp = copy_array(alias->command);
            repars_command(head, temp);
            return (get_command_alias(head, head->cmd_list->argument,
            alias->alias));
        }
        alias = alias->next;
    }
    return 0;
}

static int check_alias_existing(head_t *head, char **cmd)
{
    alias_t *temp = head->alias;

    while (temp != NULL) {
        if (strcmp(temp->alias, cmd[1]) == 0) {
            destroy_array(&temp->command);
            temp->command = copy_array(cmd + 2);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

static void stock_alias(head_t *head, char **cmd)
{
    alias_t *last_element;

    if (head->alias == NULL) {
        head->alias = malloc(sizeof(alias_t));
        head->alias->alias = strdup(cmd[1]);
        head->alias->command = copy_array(cmd + 2);
        head->alias->next = NULL;
        head->exit_status = 0;
    }
    else {
        if (check_alias_existing(head, cmd) == true)
            return;
        last_element = get_last_alias(head->alias);
        last_element->next = malloc(sizeof(alias_t));
        last_element->next->alias = strdup(cmd[1]);
        last_element->next->command = copy_array(cmd + 2);
        last_element->next->next = NULL;
        head->exit_status = 0;
    }
}

void builtin_alias(head_t *head, char **cmd)
{
    int nb_element = count_nb_element_array(cmd);

    if (nb_element == 1) {
        print_alias(head->alias);
        head->exit_status = 0;
        if (head->pipe_info.is_in_pipe == true)
            exit(0);
        return;
    }
    if (nb_element == 2) {
        print_command_alias(head->alias, cmd[1]);
        head->exit_status = 0;
        if (head->pipe_info.is_in_pipe == true)
            exit(0);
        return;
    }
    stock_alias(head, cmd);
    if (head->pipe_info.is_in_pipe == true)
        exit(0);
}