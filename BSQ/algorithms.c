/*
** EPITECH PROJECT, 2020
** Algorithms
** File description:
** Algorithms
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int my_putstr(char const *str);

char **mem_alloc_2d_array(int nb_rows, int nb_cols);

int find_biggest_square(char **map, int *n_rows, int row, int col);

char *load_file_in_mem(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *dest = malloc(sizeof(char) * 100000);
    int i = 0;
    int size = read(fd, dest + i, 99999 - i);

    while (size > 0) {
        i = i + size;
        size = read(fd, dest + i, 99999 - i);
    }
    dest[i] = '\0';
    return (dest);
}

char *load_file(char const *filepath, int rows, int colums)
{
    int fd = open(filepath, O_RDONLY);
    int nb_size = rows * (colums + 2);
    char *dest = malloc(sizeof(char) * nb_size + 1);
    int i = 0;
    int size = read(fd, dest + i, nb_size - i);

    while (size > 0) {
        i = i + size;
        size = read(fd, dest + i, nb_size - i);
    }
    dest[i] = '\0';
    return (dest);
}

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    int fd = open(filepath, O_RDONLY);
    char *s1 = load_file(filepath, nb_rows, nb_cols);
    char **dest = mem_alloc_2d_array(nb_rows + 1, nb_cols);
    int b = 0;
    int i = 0;
    int x = 0;

    for (i = 0; i <= nb_rows; i++) {
        for (x = 0; s1[b] != '\n' && s1[b] != 0; x++) {
            dest[i][x] = s1[b++];
        }
        dest[i][x] = 0;
        b = b + 1;
    }
    dest[i - 1] = 0;
    return (dest);
}

int is_square_of_size(char **map, int row, int col, int square_size)
{
    int columns = col;
    int rows = row;
    int x = 0;

    for (int i = 0; i < square_size; i++) {
        while (map[rows][columns] != 'o' && x < square_size) {
            x = x + 1;
            columns = columns + 1;
        }
        if (x != square_size)
            return (0);
        x = 0;
        columns = col;
        rows = rows + 1;
    }
    return (1);
}
