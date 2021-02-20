/*
** EPITECH PROJECT, 2020
** EPITECH PROJECT, 2020
** File description:
** putchar
*/

#include <unistd.h>
void display_space(int length, int *flags);

void my_putchar_flags(char c, int *flags)
{
    display_space(1, flags);
    write(1, &c, 1);
}
