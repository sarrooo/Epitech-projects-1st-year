/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concatenates 2 strings
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int size_d = my_strlen(dest);
    int size_s =  my_strlen(src);
    int i;

    for (i = 0; i < size_d + size_s; i++) {
        if (i == size_d) {
            for (int j = 0; i <= size_d + size_s; j++) {
                dest[i] = src[j];
                i++;
            }
        }
    }
    return (dest);
}
