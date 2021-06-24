/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** count_array_element
*/

#include "shell42.h"

int count_nb_element_array(char **array)
{
    int i;

    for (i = 1; array[i] != NULL; i++);
    return i;
}