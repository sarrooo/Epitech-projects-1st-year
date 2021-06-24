/*
** EPITECH PROJECT, 2020
** EPITECH PROJECT, 2020
** File description:
** day4
*/

void my_putchar(char c);

int my_strlen_octale(char const *str)
{
    int i;
    int k = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            k += 3;
        }
        k++;
    }
    return (k);
}

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}