/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** destroy_array
*/

#include "stddef.h"
#include <stdlib.h>

void destroy_array(char ***array)
{
    if ((*array) == NULL)
        return;
    for (int i = 0; (*array)[i] != NULL; i++) {
        free((*array)[i]);
    }
    free(*array);
    *array = NULL;
}