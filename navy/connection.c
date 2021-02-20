/*
** EPITECH PROJECT, 2020
** navy
** File description:
** connection between players
*/

#include "include/my.h"
#include "printf/my.h"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int player_connection(int pid)
{
    int error;

    error = kill(pid, SIGUSR2);
    return (error);
}

int connection(int ac, char **av)
{
    if (ac == 2) {
        my_printf("my_pid: %d\n", getpid());
        my_printf("waiting for enemy connection...\n");
    }
    return (0);
}

int connection_2(int ac, char **av)
{
    if (ac == 3) {
        my_printf("my_pid: %d\n", getpid());
        if (player_connection(my_getnbr(av[2])) == 0)
            my_printf("successfully connected\n");
        else {
            my_printf("wrong pid\n");
            return 84;
        }
    }
    return (0);
}

int main_connection(int ac, char **av)
{
    if (ac < 2 || ac > 3)
        return (84);
    if (ac == 2)
        return (connection(ac, av));
    if (ac == 3)
        return (connection_2(ac, av));
    return 0;
}