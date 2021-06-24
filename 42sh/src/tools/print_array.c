/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** print_array
*/

#include "stdio.h"

void print_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        printf("%s\n", array[i]);
    }
}