/*
** EPITECH PROJECT, 2020
** navy
** File description:
** main
*/

#include "include/my.h"
#include "printf/my.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int helper(int argc, char **argv);

int launch(int ac, char **av, info *player)
{
    player = malloc(sizeof(info));
    player->nb_player = 1;
    load_map(ac, av, player);
    if (set_pos(ac, av, player) == 84)
        return (84);
    display_pid(player->nb_player);
    recept_signal(player, 1);
    print_map(player);
    send_signal(player->pidusr2, 1);
    loop_first_player(player);
}

int loop_first_player(info *player)
{
    int i = 1;
    int won = 0;
    while (won != 1) {
        turnplayer1(i, player);
        i = (i == 1) ? 2 : 1;
        if (i == 1)
            print_map(player);
        if (check_win(player) == 1)
            return (0);
    }
    return (0);
}

int launch_for_second_player(int ac, char **av, info *player)
{
    player = malloc(sizeof(info));
    player->nb_player = 2;
    load_map(ac, av, player);
    if (set_pos(ac, av, player) == 84)
        return (84);
    player->pidusr1 = my_getnbr(av[1]);
    display_pid(2);
    send_signal(player->pidusr1, 2);
    recept_signal(player, 2);
    print_map(player);
    player->pidusr2 = my_getnbr(av[1]);
    loop_second_player(player);
}

int loop_second_player(info *player)
{
    int i = 2;
    int won = 0;
    while (won != 1) {
        turnplayer1(i, player);
        i = (i == 1) ? 2 : 1;
        if (i == 2)
            print_map(player);
        if (check_win(player) == 1)
            return (0);
    }
    return (0);
}

int main(int argc, char **argv)
{
    info *start;

    if (helper(argc, argv) == 1)
        return (0);
    if (argc == 2){
        return (launch(argc, argv, start));
    } else if (argc == 3) {
        return (launch_for_second_player(argc, argv, start));
    } else {
        return (84);
    }
    return (0);
}