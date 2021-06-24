/*
** EPITECH PROJECT, 2021
** defender
** File description:
** helper
*/

#include "../include/defender.h"

void helper(void)
{
    int file = open("./helper/help.txt", O_RDONLY);
    char buffer;

    if (file < 0) {
        write(2, "help.txt in helper directory is not readable.", 45);
    }
    while (read(file, &buffer, 1) > 0) {
        my_putchar(buffer);
    }
    close(file);
}