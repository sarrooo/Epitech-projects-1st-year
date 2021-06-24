/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** set
*/

#include "shell42.h"

static int remove_first_element(head_t *head, char *name)
{
    env_list_t *first = head->var;
    env_list_t *temp;

    if (strcmp(name, "*") == 0) {
        destroy_env_list(&head->var);
        return 1;
    }
    if (strcmp(first->name, name) == 0) {
        temp = first->next;
        free(first->name);
        free(first->value);
        free(first);
        head->var = temp;
        return 1;
    }
    return 0;
}

static int remove_last_element(head_t *head, char *name, env_list_t *first)
{
    env_list_t *temp;

    if (strcmp(name, "*") == 0) {
        destroy_env_list(&head->var);
        return 1;
    }
    if (strcmp(first->next->name, name) == 0) {
        temp = first->next;
        free(temp->name);
        free(temp->value);
        free(temp);
        first->next = NULL;
        return 1;
    }
    return 0;
}

static void remove_element_var(head_t *head, char *name)
{
    env_list_t *first = head->var;
    env_list_t *temp;

    if (remove_first_element(head, name))
        return;
    while (first->next->next != NULL) {
        if (strcmp(name, "*") == 0) {
            destroy_env_list(&head->var);
            return;
        }
        if (strcmp(first->next->name, name) == 0) {
            temp = first->next;
            first->next = temp->next;
            free(temp->name);
            free(temp->value);
            free(temp);
            return;
        }
        first = first->next;
    } remove_last_element(head, name, first);
}

void builtin_unset(head_t *head, char **cmd)
{
    env_list_t *var = head->var;

    if (count_nb_element_array(cmd) == 1) {
        dprintf(2, "unset: Too few arguments.\n");
        head->exit_status = 1;
        if (head->pipe_info.is_in_pipe == true)
            exit(1);
        return;
    }
    for (int i = 1; cmd[i] != NULL; i++) {
        remove_element_var(head, cmd[i]);
    }
    if (head->pipe_info.is_in_pipe == true)
        exit(0);
}