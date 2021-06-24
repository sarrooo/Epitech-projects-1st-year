/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** error_handling
*/

#include "shell42.h"

static void remove_element_array(char ***array, int index)
{
    int nb_element = count_nb_element_array(*array);
    char **copy = copy_array(*array);
    int i = 0;

    *array = realloc(*array, sizeof(char *) * nb_element);
    for (i = 0; i < index; i++)
        (*array)[i] = strdup(copy[i]);
    i++;
    for (i; copy[i] != NULL; i++)
        (*array)[i - 1] = strdup(copy[i]);
    (*array)[i - 1] = NULL;
    destroy_array(&copy);
}

static int is_globbing_pattern(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '*' || str[i] == '?')
            return true;
        if (str[i] == '[' || str[i] == '{')
            return true;
        if (str[i] == '~')
            return true;
    }
    return false;
}

int check_no_match(head_t *head, glob_t **glob_struct,
int *i, int *nb_no_match)
{
    if (is_globbing_pattern(head->cmd_list->argument[*i])) {
        if (*i == 0) {
            dprintf(2, "%s: No match.\n", head->cmd_list->argument[0]);
            head->exit_status = 1;
            globfree(*glob_struct);
            free(*glob_struct);
            return 1;
        }
        else {
            remove_element_array(&head->cmd_list->argument, *i);
            *nb_no_match += 1;
            *i -= 1;
        }
    }
    return 0;
}

int check_args_no_match(head_t *head, int nb_no_match, int nb_element)
{
    if (nb_no_match != 0 && nb_no_match == nb_element - 1) {
        dprintf(2, "%s: No match.\n", head->cmd_list->argument[0]);
        head->exit_status = 1;
        return 1;
    }
    return 0;
}