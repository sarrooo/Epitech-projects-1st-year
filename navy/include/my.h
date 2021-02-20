/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** prototype of function
*/

#ifndef MY_H_

#include "../printf/my.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

typedef struct info
{
    int nb_player;
    char **map;
    char **enemy;
    int pidusr1;
    int pidusr2;

    int hitted;
}info;

typedef struct signalusr
{
    int pidusr1;
    int pidusr2;
    int pid_sender;
    int signal;

    int temp;
    int value1;
    int value2;
    int breaks;

    int hit;
    int hit_change;
}signalusr;

typedef struct variable
{
    int x;
    int i;
    int j;
}variable;

extern signalusr sig;

int navy_strcmp(char const *s1, char const *s2);

int player_connection(int pid);

int connection(int ac, char **av);

int connection_2(int ac, char **av);

int main_connection(int ac, char **av);

char *load_pos(char **av, int player);

void load_map(int ac, char **av, info *player);

void print_map(info *player);

void load_enemy(int ac, char **av, info *player);

int set_pos(int ac, char **av, info *player);

char **array_copy(char **map);

int display_pid(int nb_player);

int send_signal(int pid, int usr);

int recept_signal(info *player, int player_id);

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void turnplayer1(int id, info *player);

int send_pos(int pid, int value1, int value2);

int receive_pos(info *player);

int error_handling(char *pos, int x, int i);

int error_handling_2(char *pos);

int error_map(char **map_cpy, variable var, int s, char *pos);

int update_map(info *player, char *pos);

int update_map_p2(info *player, int i, char *pos);

int check_win(info *player);

int check_win_2(info *player, int i);

int send_hit(int pid, int value);

int receive_hit(info *player, char *buffer);

int loop_second_player(info *player);

int loop_first_player(info *player);

#endif