/*
** EPITECH PROJECT, 2020
** navy
** File description:
** load position
*/

#include "include/my.h"
#include "printf/my.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

char *load_pos(char **av, int player)
{
    int fd = open(av[player], O_CREAT);
    char *buffer = malloc(sizeof(char) * 32);

    if (fd == -1)
        return (NULL);
    if (read(fd, buffer, 32) == -1)
        return (NULL);
    buffer[31] = 0;
    return (buffer);
}

void load_map(int ac, char **av, info *player)
{
    player->map = malloc(sizeof(char *) * 11);
    player->map[0] = " |A B C D E F G H\n\0";
    player->map[1] = "-+---------------\n\0";
    player->map[2] = "1|. . . . . . . .\n\0";
    player->map[3] = "2|. . . . . . . .\n\0";
    player->map[4] = "3|. . . . . . . .\n\0";
    player->map[5] = "4|. . . . . . . .\n\0";
    player->map[6] = "5|. . . . . . . .\n\0";
    player->map[7] = "6|. . . . . . . .\n\0";
    player->map[8] = "7|. . . . . . . .\n\0";
    player->map[9] = "8|. . . . . . . .\n\0";
    player->map[10] = 0;
    load_enemy(ac, av, player);
}

void load_enemy(int ac, char **av, info *player)
{
    player->enemy = malloc(sizeof(char *) * 11);
    player->enemy[0] = " |A B C D E F G H\n\0";
    player->enemy[1] = "-+---------------\n\0";
    player->enemy[2] = "1|. . . . . . . .\n\0";
    player->enemy[3] = "2|. . . . . . . .\n\0";
    player->enemy[4] = "3|. . . . . . . .\n\0";
    player->enemy[5] = "4|. . . . . . . .\n\0";
    player->enemy[6] = "5|. . . . . . . .\n\0";
    player->enemy[7] = "6|. . . . . . . .\n\0";
    player->enemy[8] = "7|. . . . . . . .\n\0";
    player->enemy[9] = "8|. . . . . . . .\n\0";
    player->enemy[10] = 0;
}

char **array_copy(char **map)
{
    char **map_cpy = malloc(sizeof(char *) * 11);
    int j = 0;
    int i = 0;

    for (i = 0; i < 10; i++) {
        map_cpy[i] = malloc(sizeof(char) * 19);
        for (j = 0; j < 18; j++) {
            map_cpy[i][j] = map[i][j];
        }
        map_cpy[i][j] = 0;
    }
    map_cpy[10] = 0;
    return (map_cpy);
}