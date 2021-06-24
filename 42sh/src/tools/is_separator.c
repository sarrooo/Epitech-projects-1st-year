/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** is_separator
*/

#include "shell42.h"

int is_double_separator(char letter)
{
    if (letter == '&')
        return true;
    if (letter == '|' || letter == '&')
        return true;
    if (letter == '>' || letter == '<')
        return true;
    return false;
}

int is_simple_separator(char letter)
{
    if (letter == '(' || letter == ')')
        return true;
    if (letter == ';')
        return true;
    return false;
}