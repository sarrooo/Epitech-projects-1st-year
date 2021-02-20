/*
** EPITECH PROJECT, 2020
** navy
** File description:
** update map
*/

#include "include/my.h"
#include "printf/my.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int update_map(info *player, char *pos) //Receiver
{
    int s = (pos[0] - 63) - 2;

    if (player->map[pos[1] - 47][pos[0] - 63 + s] == '.') {
        player->map[pos[1] - 47][pos[0] - 63 + s] = 'o';
        return (0);
    }
    else {
        player->map[pos[1] - 47][pos[0] - 63 + s] = 'x';
        return (1);
    }
}

int update_map_p2(info *player, int i, char *pos) //Sender
{
    int s = (pos[0] - 63) - 2;
    char **map_enemy = array_copy(player->enemy);

    if (i == 0)
        map_enemy[pos[1] - 47][pos[0] - 63 + s] = 'o';
    else
        map_enemy[pos[1] - 47][pos[0] - 63 + s] = 'x';
    player->enemy = map_enemy;
}

int check_win_2(info *player, int i)
{
    int ok = 0;

    for (int j = 0; j < 17; j++)
        if (player->enemy[i][j] == 'x')
            ok++;
    return (ok);
}

int check_win_3(info *player, int i)
{
    int ok = 0;

    for (int j = 0; j < 17; j++)
        if (player->map[i][j] == 'x')
            ok++;
    return (ok);
}

int check_win(info *player)
{
    int ok = 0;

    for (int i = 0; i < 10; i++)
        ok += check_win_2(player, i);
    if (ok >= 14) {
        print_map(player);
        my_printf("I won\n\n");
        return (1);
    }
    ok = 0;
    for (int i = 0; i < 10; i++)
        ok += check_win_3(player, i);
    if (ok >= 14) {
        print_map(player);
        my_printf("Enemy won\n\n");
        return (1);
    }
    return (0);
}