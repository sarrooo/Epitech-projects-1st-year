/*
** EPITECH PROJECT, 2020
** printf
** File description:
** display space with width
*/

void my_putchar(char c);

void display_space(int length, int *flags)
{
    for (int i = length; i < flags[6]; i++) {
        my_putchar(' ');
    }
    flags[6] = 0;
    return;
}

void display_zero(int length, int *flags)
{
    for (int i = length; i < flags[6]; i++) {
        my_putchar('0');
    }
    flags[6] = 0;
    return;
}