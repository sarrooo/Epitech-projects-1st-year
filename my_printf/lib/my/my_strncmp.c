/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** find a n string
*/
int my_strncmp(char const *s1, char const *s2, int n)
{
    int result;

    for (int i = 0; i <= n; i++) {
        if (s1[i] != s2[i]) {
            result = s2[i] - s1[i];
            return (result);
        }
    }
    return (0);
}
