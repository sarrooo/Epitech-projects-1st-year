/*
** EPITECH PROJECT, 2020
** navy
** File description:
** print map
*/

#include "include/my.h"
#include "printf/my.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void print_map(info *player)
{
    my_printf("my positions:\n");
    my_show_word_array(player->map);
    my_printf("\n");
    my_printf("enemy's positions:\n");
    my_show_word_array(player->enemy);
    my_printf("\n");
}