/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** copy n character
*/

int i_cpy(int i, char *dest, int n)
{
    while (i != n) {
        dest[i] = '\0';
        i++;
    }
    return (i);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;
    int max2 = 0;

    while (src[max2] != '\0') {
        max2 = max2 + 1;
    }
    for (i = 0; i < n; i++) {
        if (src[i] == '\0') {
            i = i_cpy(i, dest, n);
        }
        else
            dest[i] = src[i];
    }
    return (dest);
}
