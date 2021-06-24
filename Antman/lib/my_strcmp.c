/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** task06
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int result;

    if (my_strlen(s1) > my_strlen(s2))
        return (-1);
    if (my_strlen(s2) > my_strlen(s1))
        return (1);
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            result = s2[i] - s1[i];
            return (result);
        }
    }
    return (0);
}
