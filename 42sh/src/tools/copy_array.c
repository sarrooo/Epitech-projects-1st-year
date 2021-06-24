/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** copy_array
*/

#include "shell42.h"

char **copy_array(char **array)
{
    int nb_element = count_nb_element_array(array);
    char **new_array = malloc(sizeof(char *) * (nb_element + 1));
    int i = 0;

    for (i = 0; array[i] != NULL; i++) {
        new_array[i] = strdup(array[i]);
    }
    new_array[i] = NULL;
    return new_array;
}