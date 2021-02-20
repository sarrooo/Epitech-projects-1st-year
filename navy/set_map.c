/*
** EPITECH PROJECT, 2020
** navy
** File description:
** set map
*/

#include "include/my.h"
#include "printf/my.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

char *draw_pos(int x, int i, char *pos, char **map_cpy)
{
    int a = 47;
    int b = 63;
    int space = (pos[x] - 63) - 2;

    if (pos[x] < 65 || pos[x] > 72)
        return (NULL);
    if (pos[x + 3] < 65 || pos[x + 3] > 72)
        return (NULL);
    if (pos[x + 1] < 49 || pos[x + 1] > 56)
        return (NULL);
    if (pos[x + 4] < 49 || pos[x + 4] > 56)
        return (NULL);
    if (i == 0)
        return (pos);
    if (pos[x + 1] == pos[x + 4]) {
        pos[x] = pos[x] + 1;
    }
    else
        pos[x + 1] = pos[x + 1] + 1;
    return (pos);
}

variable set_pos2(variable var, char **map_cpy, char *pos)
{
    int s = (pos[var.x] - 63) - 2;
    int *return_int = malloc(sizeof(int) * 2);

    while (var.i <= var.j - 1) {
        pos = draw_pos(var.x, var.i, pos, map_cpy);
        if (pos == NULL) {
            var.x = -1;
            return (var);
        }
        s = (pos[var.x] - 63) - 2;
        if (error_map(map_cpy, var, s, pos) == 84) {
            var.x = -1;
            return (var);
        }
        map_cpy[pos[var.x + 1] - 47][pos[var.x] - 63 + s] = var.j + 48;
        var.i++;
    }
    var.x = var.x + 4;
    return (var);
}

int set_pos(int ac, char **av, info *player)
{
    char *pos = load_pos(av, player->nb_player);
    char **map_cpy = array_copy(player->map);
    variable var;

    var.x = 2;
    if (pos == NULL || error_handling_2(pos) == 84) {
        write(2, "wrong entry\n", 12);
        return (84);
    }
    for (var.j = 2; var.x != -1 && var.j < 6; var.j++) {
        for (var.i = 0; var.x != -1 && var.i < var.j; var.i++)
            var = set_pos2(var, map_cpy, pos);
        if (var.x == -1) {
            write(2, "wrong entry", 12);
            return (84);
        }
        var.x = var.x + 4;
    }
    pos = load_pos(av, player->nb_player);
    player->map = map_cpy;
    return (1);
}