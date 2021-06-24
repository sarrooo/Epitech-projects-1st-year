/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** command_line_to_array
*/

#include "shell42.h"

char **my_str_to_word_array(char const *str);

void command_line_to_array(head_t *head)
{
    int nb_space_tab = 0;
    int i = 0;

    for (i = 0; head->command_line[i] != 0; i++) {
        if (head->command_line[i] == 32)
            nb_space_tab++;
        if (head->command_line[i] == 9)
            nb_space_tab++;
    }
    if (i == nb_space_tab) {
        head->command_array = malloc(sizeof(char *));
        head->command_array[0] = NULL;
    }
    else {
        head->command_array = my_str_to_word_array(head->command_line);
    }
}