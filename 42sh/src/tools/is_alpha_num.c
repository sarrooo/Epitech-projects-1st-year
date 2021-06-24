/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** is_alpha_num
*/

#include "shell42.h"

int is_alpha_num(char letter)
{
    if (letter >= 'A' && letter <= 'Z')
        return true;
    if (letter >= 'a' && letter <= 'z')
        return true;
    if (letter >= '0' && letter <= '9')
        return true;
    return false;
}