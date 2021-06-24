/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** unalias
*/

#include "shell42.h"

/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** unsetenv
*/

#include "shell42.h"

static int remove_first_element(head_t *head, char *name)
{
    alias_t *first = head->alias;
    alias_t *temp;

    if (strcmp(name, "*") == 0) {
        destroy_alias(head->alias);
        head->alias = NULL;
        return 1;
    }
    if (strcmp(first->alias, name) == 0) {
        temp = first->next;
        free(first->alias);
        destroy_array(&first->command);
        free(first);
        head->alias = temp;
        return 1;
    }
    return 0;
}

static int remove_last_element(head_t *head, char *name, alias_t *first)
{
    alias_t *temp;

    if (strcmp(name, "*") == 0) {
        destroy_alias(head->alias);
        head->alias = NULL;
        return 1;
    }
    if (strcmp(first->next->alias, name) == 0) {
        temp = first->next;
        free(first->alias);
        destroy_array(&first->command);
        free(first);
        head->alias = temp;
        return 1;
    }
    return 0;
}

static void remove_element_alias(head_t *head, char *name)
{
    alias_t *first = head->alias;
    alias_t *temp;

    if (remove_first_element(head, name))
        return;
    while (first->next->next != NULL) {
        if (strcmp(name, "*") == 0) {
            destroy_alias(head->alias);
            head->alias = NULL;
            return;
        } else if (strcmp(first->next->alias, name) == 0) {
            temp = first->next;
            first->next = temp->next;
            free(temp->alias);
            destroy_array(&temp->command);
            free(temp);
            return;
        }
        first = first->next;
    }
    remove_last_element(head, name, first);
}

void builtin_unalias(head_t *head, char **cmd)
{
    if (count_nb_element_array(cmd) == 1) {
        dprintf(2, "unalias: Too few arguments.\n");
        head->exit_status = 1;
        if (head->pipe_info.is_in_pipe == true)
            exit(1);
        return;
    }
    for (int i = 1; cmd[i] != NULL; i++) {
        remove_element_alias(head, cmd[i]);
    }
    if (head->pipe_info.is_in_pipe == true)
        exit(1);
}