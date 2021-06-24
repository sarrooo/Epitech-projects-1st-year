/*
** EPITECH PROJECT, 2021
** lib
** File description:
** my_strconcat
*/

#include <stdlib.h>
int my_strlen(char const *str);

void my_strcat_ahead(char *src, char *dest)
{
    int i;
    int k;
    char *temp = malloc(sizeof(char) + my_strlen(dest) + 1);

    for (k = 0; dest[k] != '\0'; k++)
        temp[k] = dest[k];
    temp[k] = '\0';
    for (i = 0; src[i] != '\0'; i += 1)
        dest[i] = src[i];
    for (k = 0; temp[k] != '\0'; k++)
        dest[i + k] = temp[k];
    dest[i + k] = '\0';
    return;
}