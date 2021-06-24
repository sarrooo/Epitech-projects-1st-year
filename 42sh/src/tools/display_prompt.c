/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** display_prompt
*/

#include "shell42.h"

void display_prompt(void)
{
    if (isatty(0) == 1)
        printf("$> ");
}