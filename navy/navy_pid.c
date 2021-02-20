/*
** EPITECH PROJECT, 2020
** navy
** File description:
** display pid
*/

#include "include/my.h"

int display_pid(int nb_player)
{
    pid_t info_pid = getpid();
    my_printf("my_pid: %d\n", info_pid);
    if (nb_player == 1) {
        my_printf("waiting for enemy connection...\n");
    }
}
