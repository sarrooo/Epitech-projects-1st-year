/*
** EPITECH PROJECT, 2020
** read_arr
** File description:
** Read array in 2d
*/

int det_nb(int nb, int numbers)
{
    if (nb == numbers)
        return (1);
    return (0);
}

int array_2d_how_many(int **arr, int nb_rows, int nb_cols, int number)
{
    int res = 0;

    for (int x = 0; x < nb_rows; x++)
        for (int i = 0; i < nb_cols; i++)
            res = res + det_nb(arr[x][i], number);
    return (res);
}

int first_len(int len, char *buff, int x)
{
    for (int z = x; buff[z] != '\n' && buff[z] != 0; z++)
        len++;
    return (len);
}
