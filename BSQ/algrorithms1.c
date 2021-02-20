/*
** EPITECH PROJECT, 2020
** Algo for bsq
** File description:
** 2/2
*/

int return_sq_size(int x, int nb_rows)
{
    if (x == 0 && nb_rows == 0)
        return (0);
    if (x == 0)
        return (nb_rows);
    if (x >= nb_rows + 1 || x == 0)
        return (nb_rows + 1);
    else
        return (x);
}

int is_square_of_x(char **map, int row, int col, int square_size)
{
    int columns = col;
    int rows = row;
    int x = 0;
    int nb_rows = 0;

    for (int i = 0; i < square_size; i++) {
        if (map[rows] == 0)
            return (return_sq_size(x, nb_rows));
        for (x = 0; map[rows][columns] != 'o' && x < square_size; x++)
            columns = columns + 1;
        if (x < square_size)
            square_size = x;
        if (nb_rows > square_size || x > square_size)
            return (return_sq_size(x, nb_rows));
        nb_rows = nb_rows + 1;
        columns = col;
        rows = rows + 1;
    }
    return (square_size);
}

int find_biggest_square(char **map, int *nb_row_cols, int row, int col)
{
    int sq_size = 0;
    int columns = col;
    int rows = row;
    int nb_rows = 1;

    while (map[row][columns] != 'o' && columns != nb_row_cols[1]) {
        columns = columns + 1;
        sq_size = sq_size + 1;
    }
    if (sq_size == 0)
        return (0);
    sq_size = is_square_of_x(map, row, col, sq_size);
    return (sq_size);
}
