/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** main bsq
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/bs.h"
#include <stdio.h>

int get_len(char *filepath, int nb_lines)
{
    int fd = open(filepath, O_RDONLY);
    char *buff = malloc(sizeof(char) * 1000000000);
    int x = 0;
    int len = 0;
    int len_temp = 0;

    read(fd, buff, 999999999);
    for (x; buff[x] != '\n' && buff[x] != 0; x++);
    x = x + 1;
    len = first_len(len, buff, x);
    for (int b = 0; b < nb_lines; b++) {
        len_temp = len;
        len = 0;
        for (x; buff[x] != '\n' && (buff[x] == '.' || buff[x] == 'o'); x++)
            len++;
        if (len_temp != len)
            return (-1);
        x = x + 1;
    }
    free(buff);
    return (len);
}

int *max_square(int *pos_max, int max, int y, int x)
{
    if (max > pos_max[2]) {
        pos_max[0] = y;
        pos_max[1] = x;
        pos_max[2] = max;
    }
    return (pos_max);
}

int modif_str(int *pos_max, char **str, int *nb_line)
{
    int y = pos_max[0];
    int x = pos_max[1];
    int size = pos_max[2];

    for (int i = x; i < pos_max[2] + x && i < nb_line[0]; i++) {
        for (int b = y; b < pos_max[2] + y && b - y < nb_line[0]; b++) {
            str[i][b] = 'x';
        }
    }
    my_show_word_array(str);
    return (0);
}

int *one_line(int *nb_line, int *pos_max, char **av)
{
    int max = 0;
    char **str = load_2d_arr_from_file(av[1], nb_line[0] + 1, nb_line[1] + 2);

    for (int x = 0; x < nb_line[0] && max <= 0; x++)
        for (int y = 0; y < nb_line[1] && max <= 0; y++) {
            max = find_biggest_square(str + 1, nb_line, x, y);
            pos_max = max_square(pos_max, max, y, x);
        }
    if (max > 0)
        pos_max[2] = 1;
    return (pos_max);
}

int main(int ac, char **av)
{
    int *nb_line = malloc(sizeof(int) * 2);
    char **str;
    int max = 0;
    int *pos_max = malloc(sizeof(int) * 3);

    pos_max[0] = 0;
    pos_max[1] = 0;
    pos_max[2] = 0;
    nb_line[0] = fs_get_number_from_first_line(av[1]);
    nb_line[1] = get_len(av[1], nb_line[0]);
    if (nb_line[0] <= 0 || nb_line[1] <= 0 || fs_open_file(av[1]) == 84)
        return (84);
    if (nb_line[0] == 1 || nb_line[1] == 1)
        pos_max = one_line(nb_line, pos_max, av);
    str = load_2d_arr_from_file(av[1], nb_line[0] + 1, nb_line[1] + 2);
    for (int x = 0; x < nb_line[0] - 2; x++)
        for (int y = 0; y < nb_line[1]; y++) {
            max = find_biggest_square(str + 1, nb_line, x, y);
            pos_max = max_square(pos_max, max, y, x);
        }
    return (modif_str(pos_max, str + 1, nb_line));
}
