/*
** EPITECH PROJECT, 2021
** B  -PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** check_globbing
*/

#include "shell42.h"

static void concanate_array(head_t *head, glob_t *glob_struct, int i)
{
    int j = 0;
    char **temp = copy_array(head->cmd_list->argument);
    int nb_element = count_nb_element_array(head->cmd_list->argument) + 1;

    destroy_array(&head->cmd_list->argument);
    head->cmd_list->argument = malloc(sizeof(char *) *
    (glob_struct->gl_pathc + nb_element));
    for (j = 0; j < i; j++)
        head->cmd_list->argument[j] = strdup(temp[j]);
    for (int x = 0; glob_struct->gl_pathv[x] != NULL; x++, j++)
        head->cmd_list->argument[j] = strdup(glob_struct->gl_pathv[x]);
    for (int k = i + 1; temp[k] != NULL; k++, j++)
        head->cmd_list->argument[j] = strdup(temp[k]);
    head->cmd_list->argument[j] = NULL;
    destroy_array(&temp);
}

int check_globbing(head_t *head, char **cmd)
{
    glob_t *glob_struct;
    int status = 0;
    int nb_no_match = 0;
    int nb_element = count_nb_element_array(cmd);

    for (int i = 0; head->cmd_list->argument[i] != NULL; i++) {
        glob_struct = malloc(sizeof(glob_t));
        status =
        glob(head->cmd_list->argument[i], GLOB_ERR, NULL, glob_struct);
        if (status == 0) {
            concanate_array(head, glob_struct, i);
            i += glob_struct->gl_pathc - 1;
        } else if (check_no_match(head, &glob_struct, &i, &nb_no_match))
            return 1;
        globfree(glob_struct);
        free(glob_struct);
    }
    if (check_args_no_match(head, nb_no_match, nb_element))
        return 1;
    return 0;
}