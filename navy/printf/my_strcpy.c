/*
** EPITECH PROJECT, 2020
** EPITECH PROJECT, 2020
** File description:
** copy string
*/

#include <stdlib.h>

void my_putchar(char c);

int my_strlen(char *str);

char *my_strcpy(char *dest, char *src)
{
    int i = 0;
    dest = malloc(sizeof(char) * my_strlen(src) + 1);

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
