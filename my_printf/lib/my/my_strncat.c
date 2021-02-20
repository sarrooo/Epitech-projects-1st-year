/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** add src to dest for n
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int size_d = my_strlen(dest);
    int size_s = my_strlen(src);
    int i;

    for (i = 0; i < size_d + size_s; i++) {
        if (i == size_d) {
            for (int j = 0; i < size_d + nb; j++) {
                dest[i] = src[j];
                i++;
            }
            dest[i] = 0;
        }
    }
    return (dest);
}
