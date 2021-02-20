/*
** EPITECH PROJECT, 2020
** navy
** File description:
** receive_pos
*/

#include "include/my.h"

void receive_sig(int signum, siginfo_t *info, void* context)
{
    if (signum == SIGUSR1) {
        sig.temp += 1;
    }
    if (signum == SIGUSR2) {
        sig.breaks = 1;
    }
    return;
}

int fill_buffer(char *buffer, char a, char b, info *player)
{
    buffer[0] = a + 64;
    buffer[1] = b + 47;
    buffer[2] = '\0';
    player->hitted = update_map(player, buffer);
    if (player->hitted == 1)
        my_printf("%s: hit\n\n");
    else
        my_printf("%s: missed\n\n");
    return (0);
}

int receive_pos(info *player)
{
    struct sigaction action;
    char buffer[3];

    sig.temp = 0;
    sig.breaks = 0;
    sigemptyset(&action.sa_mask);
    action.sa_sigaction = &receive_sig;
    action.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    while (sig.breaks == 0) {
        usleep(2);
    }
    sig.breaks = 0;
    sig.value1 = sig.temp;
    sig.temp = 0;
    while (sig.breaks == 0) {
        usleep(2);
    }
    sig.value2 = sig.temp;
    return (fill_buffer(buffer, sig.value1, sig.value2, player));
}

void receive_sig_hit(int signum, siginfo_t *info, void* context)
{
    if (signum == SIGUSR1) {
        sig.hit = 1;
        sig.hit_change = 1;
    }
    if (signum == SIGUSR2) {
        sig.hit = 0;
        sig.hit_change = 1;
    }
    return;
}

int receive_hit(info *player, char *buffer)
{
    struct sigaction action;

    sigemptyset(&action.sa_mask);
    action.sa_sigaction = &receive_sig_hit;
    action.sa_flags = SA_SIGINFO;
    sig.hit_change = 0;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    while (sig.hit_change == 0) {
        usleep(10);
    }
    if (sig.hit == 1) {
        my_printf(" hit\n");
        update_map_p2(player, 1, buffer);
        return (1);
    } else {
        my_printf(" missed\n");
        update_map_p2(player, 0, buffer);
        return (0);
    }
}