/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** reverse string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = my_strlen(str) - 1;
    int s;
    int temporaire;

    for (s = 0; s < i; s++) {
        temporaire = str[i];
        str[i] = str[s];
        str[s] = temporaire;
        i--;
    }
    return (str);
}
