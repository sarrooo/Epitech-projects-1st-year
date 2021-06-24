/*
** EPITECH PROJECT, 2021
** lib
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    int i;

    for (i = 0; dest[i] != '\0'; i += 1);
    for (int j = 0; src[j] != '\0'; i += 1, j += 1)
        dest[i] = src[j];
    dest[i] = '\0';
    return (dest);
}