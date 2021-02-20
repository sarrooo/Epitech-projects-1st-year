/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** get int
*/

#include <stdlib.h>

int my_strlen(char const *str);

static int check_nb(char const *str, int j)
{
    if ('0' <= str[j] && str[j] <= '9')
        return (0);
    if ('+' == str[j] || str[j] == '-')
        return (2);
    return (1);
}

static int int_to_int(int *dest, int a)
{
    int result = 0;
    int b = 1;

    while (a >= 0) {
        result = result + (dest[a] * b);
        a--;
        b = b * 10;
    }
    return (result);
}

int my_getnbr(char const *str)
{
    int max_1 = my_strlen(str);
    int *dest = malloc(sizeof(int) * 10);
    int a = 0;
    int n = 1;
    int result = 0;
    int fin_nb = 0;

    if (check_nb(str, 0) == 1)
        return (0);
    for (int i = 0; i <= my_strlen(str); i++) {
        if (str[i] == '-')
            n = n * -1;
        if (check_nb(str, i) == 0) {
            dest[a] = str[i] - 48;
            a++;
            if (check_nb(str, i + 1) != 0)
                break;
        }
    }
    result = int_to_int(dest, a - 1);
    return (result * n);
}
