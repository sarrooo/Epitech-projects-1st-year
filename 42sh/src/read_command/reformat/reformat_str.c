/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** separe_str
*/

#include "shell42.h"

void reformat_str(head_t *head)
{
    int nb_char = count_extra_space(head->command_line);
    char *str_clean = malloc(sizeof(char) * (nb_char + 1));
    char *str = head->command_line;
    int index_str_clean = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i + 1] != 34 && str[i + 1] != 39 && str[i + 1] != '`')
            str_clean[index_str_clean++] = str[i];
        between_quote(str, str_clean, &i, &index_str_clean);
        between_simple_quote(str, str_clean, &i, &index_str_clean);
        between_backtick(str, str_clean, &i, &index_str_clean);
        if (str[i] != 0)
            add_space_separator(str, str_clean, i, &index_str_clean);
    }
    str_clean[index_str_clean] = 0;
    free(head->command_line);
    head->command_line = str_clean;
}