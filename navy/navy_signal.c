/*
** EPITECH PROJECT, 2020
** navy
** File description:
** handle signal
*/

#include "include/my.h"
signalusr sig;

void handle_signal(int signum, siginfo_t* info, void* context)
{
    if (signum == SIGUSR1) {
        sig.pidusr1 = info->si_pid;
        my_printf("successfully connected\n\n");
        sig.signal = 1;
    }
    if (signum == SIGUSR2) {
        sig.pidusr2 = info->si_pid;
        my_printf("\nenemy connected\n\n");
        sig.signal = 1;
    }
    return;
}

int recept_signal(info *player, int player_id)
{
    struct sigaction action;

    sig.signal = 0;
    sigemptyset(&action.sa_mask);
    action.sa_sigaction = &handle_signal;
    action.sa_flags = SA_SIGINFO;
    if (player_id == 1)
        sigaction(SIGUSR2, &action, NULL);
    player->pidusr2 = sig.pidusr2;
    if (player_id == 2)
        sigaction(SIGUSR1, &action, NULL);
    while (sig.signal == 0) {
        usleep(2);
    }
    if (player_id == 1)
        player->pidusr2 = sig.pidusr2;
    if (player_id == 2)
        player->pidusr1 = sig.pidusr1;
}

int send_signal(int pid, int usr)
{
    if (usr == 1) {
        kill(pid, 10);
    } else if (usr == 2) {
        kill(pid, 12);
    } else {
        return (0);
    }
    return (0);
}