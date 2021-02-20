/*
** EPITECH PROJECT, 2020
** navy
** File description:
** turnplayer
*/

#include "include/my.h"

int check_attack(char *str, info *player)
{
    int s = (str[0] - 63) - 2;

    if (str[0] < 'A'  || str[0] > 'H') {
        return (84);
    }
    if (str[1] < '1'  || str[1] > '8') {
        return (84);
    }
    if (player->enemy[str[1] - 47][str[0] - 63 + s] == 'o') {
        return (84);
    }
    if (player->enemy[str[1] - 47][str[0] - 63 + s] == 'x') {
        return (84);
    }
    return (0);
}

int check_pos(char* buff, int id, info *player)
{
    if (check_attack(buff, player) == 84) {
        my_printf("wrong position\n");
        turnplayer1(id, player);
        return (1);
    }
    return (0);
}

void turnplayer1(int id, info *player)
{
    int len = 2;
    char buff[3];

    if (id == 2) {
        my_printf("waiting's for enemy's attack...\n");
        receive_pos(player);
        send_hit(player->pidusr2, player->hitted);
    }
    else {
        my_printf("attack: ");
        read(0, buff, sizeof(buff));
        buff[2] = '\0';
        if (check_pos(buff, id, player) == 1)
            return;
        send_pos(player->pidusr2, buff[0], buff[1]);
        my_printf("%s", buff);
        my_printf("\n%s:", buff);
        receive_hit(player, buff);
        my_printf("\n");
    }
    return;
}