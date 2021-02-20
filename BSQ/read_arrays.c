/*
** EPITECH PROJECT, 2020
** read 2d array
** File description:
** Read 2d array
*/

#include <stdlib.h>

void my_putchar(char c);

int my_putstr(char const *str);

int my_put_nbr(int nb);

void array_1d_print_chars(char const *arr)
{
    for (int i = 0; arr[i] != 0; i++) {
        my_putchar(arr[i]);
        my_putchar('\n');
    }
}

void array_1d_print_ints(int const *arr, int size)
{
    for (int i = 0; i < size; i++) {
        my_put_nbr(arr[i]);
        my_putchar('\n');
    }
}

int array_1d_sum(int const *arr, int size)
{
    int res = 0;

    for (int i = 0; i < size; i++) {
        res = res + arr[i];
    }
    return (res);
}

int array_2d_sum(int **arr, int nb_rows, int nb_cols)
{
    int res = 0;

    for (int x = 0; x < nb_rows; x++)
        for (int i = 0; i < nb_cols; i++) {
            res = res + arr[x][i];
        }
    return (res);
}
