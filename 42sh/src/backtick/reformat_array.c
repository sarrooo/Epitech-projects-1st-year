/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** reformat_array
*/

#include "shell42.h"

void get_backtick_return(head_t *head, char *cmd, int n)
{
    char **new_array = my_str_to_word_array(cmd);
    char **temp = copy_array(head->cmd_list->argument);
    int nb_new_element = count_nb_element_array(new_array) - 1;
    int nb_element = count_nb_element_array(head->cmd_list->argument);
    int i = 0;
    int j = 0;
    int index_array = 0;

    destroy_array(&head->cmd_list->argument);
    head->cmd_list->argument = malloc(sizeof(char *) *
    (nb_new_element + nb_element + 1));
    for (i = 0; i < n; i++, j++)
        head->cmd_list->argument[i] = strdup(temp[i]);
    index_array = i + 1;
    for (i = 0; new_array[i] != NULL; i++, j++)
        head->cmd_list->argument[j] = strdup(new_array[i]);
    for (j; temp[index_array] != NULL; index_array++, j++)
        head->cmd_list->argument[j] = strdup(temp[index_array]);
    head->cmd_list->argument[j] = NULL;
    destroy_array(&temp);
    destroy_array(&new_array);
}