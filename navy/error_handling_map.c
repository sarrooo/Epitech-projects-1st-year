/*
** EPITECH PROJECT, 2020
** navy
** File description:
** erro handling for placement
*/

#include "include/my.h"
#include "printf/my.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int error_map(char **map_cpy, variable var, int s, char *pos)
{
    if (map_cpy[pos[var.x + 1] - 47][pos[var.x] - 63 + s] != '.') {
        write(2, "wrong entry\n", 12);
        return (84);
    }
}

int error_handling_2(char *pos)
{
    int i = 1;

    for (int x = 2; x <= 26; x += 8) {
        if (error_handling(pos, x, i) == 84) {
            return (84);
        }
        i++;
    }
}

int error_handling(char *pos, int x, int i)
{
    if (pos[x + 1] == pos[x + 4]) {
        if (pos[x + 3] - pos[x] != i) {
            return (84);
        }
        return (0);
    }
    else if (pos[x] == pos[x + 3]) {
        if (pos[x + 4] - pos[x + 1] != i) {
            return (84);
        }
        return (0);
    }
    else
        return (84);
    return (0);
}