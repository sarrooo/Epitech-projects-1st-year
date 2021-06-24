/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** error_message
*/

#include "shell42.h"

void exec_error_message(char *str, char *message)
{
    char *error_message;

    error_message = malloc(sizeof(char) * (strlen(str) + 22));
    error_message[0] = 0;
    error_message = strcat(error_message, str);
    error_message = strcat(error_message, message);
    write(2, error_message, strlen(error_message));
    free(error_message);
}