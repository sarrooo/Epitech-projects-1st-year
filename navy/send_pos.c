/*
** EPITECH PROJECT, 2020
** navy
** File description:
** send_pos
*/

#include "include/my.h"

int send_hit(int pid, int value)
{
    if (value == 1) {
        usleep(5000);
        kill(pid, 10);
        usleep(5000);
    }
    if (value == 0) {
        usleep(5000);
        kill(pid, 12);
        usleep(5000);
    }
    return (0);
}

int send_pos(int pid, int value1, int value2)
{
    for (int i = 0; i < value1 - 64; i++) {
        usleep(5000);
        kill(pid, 10);
        usleep(5000);
    }
    usleep(5000);
    kill(pid, 12);
    for (int i = 0; i < value2 - 47; i++) {
        usleep(5000);
        kill(pid, 10);
        usleep(5000);
    }
    usleep(5000);
    kill(pid, 12);
    return (0);
}