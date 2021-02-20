/*
** EPITECH PROJECT, 2020
** EPITECH PROJECT, 2020
** File description:
** day4
*/

void my_putchar(char c);
int my_strlen(char const *str);
void display_space(int length, int *flags);

int my_putstr_flags(char const *str, int *flags)
{
    int strlen = my_strlen(str);
    if (flags[1] == 0)
        display_space(strlen, flags);
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    if (flags[1] == 1)
        display_space(strlen, flags);
    return (0);
}

int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
