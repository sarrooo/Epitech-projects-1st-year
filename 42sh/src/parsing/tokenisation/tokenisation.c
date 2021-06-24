/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** tokenisation
*/

#include "shell42.h"

token_list_t *init_token_list(head_t *head)
{
    token_list_t *token_list = NULL;
    token_type_t token_type;
    token_list_t *first_element = token_list;

    for (int i = 0; head->command_array[i] != NULL; i++) {
        if (i == 0) {
            token_list = malloc(sizeof(token_list_t));
            first_element = token_list;
        }
        token_list->next = NULL;
        token_list->command = strdup(head->command_array[i]);
        token_type = find_type_token(head->command_array[i]);
        token_list->token_type = (token_type != EMPTY) ? token_type : WORD;
        if (head->command_array[i + 1] != NULL) {
            token_list->next = malloc(sizeof(token_list_t));
            token_list = token_list->next;
        }
    }
    return first_element;
}

void destroy_token_list(token_list_t *token_list)
{
    token_list_t *temp;

    while (token_list != NULL) {
        free(token_list->command);
        temp = token_list->next;
        free(token_list);
        token_list = temp;
    }
}