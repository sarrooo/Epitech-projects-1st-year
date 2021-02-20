/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** manage map
*/

#include "include/my.h"

int read_map(int ac, char **av, list *l_a)
{
    int fd = open(av[1], O_RDONLY);
    int size_map = 1000;
    char *map = malloc(sizeof(char) * size_map);
    int i = 0;

    if (fd < 0) {
        if (my_strcmp(av[1], "-h") != 0)
            my_printf("Wrong file name\n");
        l_a->map->map_array = NULL;
        return (84);
    }
    read(fd, map, size_map - 2);
    map[size_map - 1] = '\0';
    for (i = 0; i < size_map && map[i] != 'E'; i++);
    if (i == size_map) {
        my_printf("Missing 'E' at the end of map\n");
        map = NULL;
    }
    if (map != NULL)
        map[i + 1] = 0;
    map_to_array(map, l_a);
}

int map_to_array_2(char *map, list *l_a)
{
    char **map_arr = malloc(sizeof(char *) * (l_a->map->nb_lines + 1));
    int z = 0;
    int i = 0;
    int j = 0;

    map_arr[0] = malloc(sizeof(char) * l_a->map->nb_cols);
    for (i = 0; map[i] != 'E'; i++) {
        if (map[i] == '\n') {
            map_arr[j][z] = 0;
            j++;
            map_arr[j] = malloc(sizeof(char) * l_a->map->nb_cols + 2);
            z = 0;
            i++;
        }
        map_arr[j][z++] = map[i];
    }
    map_arr[j][z] = map[i];
    map_arr[j][z + 1] = 0;
    map_arr[j + 1] = 0;
    l_a->map->map_array = map_arr;
}

int map_to_array(char *map, list *l_a)
{
    int nb_lines = 1;
    int j = 0;

    l_a->map->nb_cols = 0;
    if (map == NULL) {
        l_a->map->map_array = NULL;
        return (0);
    }
    for (int x = 0; map[x] != 'E'; x++) {
        j++;
        if (map[x] == '\n' && l_a->map->nb_cols < j)
            l_a->map->nb_cols = j;
        if (map[x] == '\n' || map[x] == 'E') {
            nb_lines++;
            j = 0;
        }
    }
    if (l_a->map->nb_cols < j)
        l_a->map->nb_cols = j;
    l_a->map->nb_lines = nb_lines;
    map_to_array_2(map, l_a);
}