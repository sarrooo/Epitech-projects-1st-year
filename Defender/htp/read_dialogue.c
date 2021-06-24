/*
** EPITECH PROJECT, 2021
** defender
** File description:
** read bubble
*/

#include "../include/defender.h"

void read_dialogue(game_t* game, char *filepath)
{
    int file = open(filepath, O_RDONLY);
    int len;

    game->map.data_htp->str = malloc(sizeof(char) * 500);
    game->map.data_htp->temp = malloc(sizeof(char) * 500);
    game->map.data_htp->temp[0] = '\0';
    sfSound_play(game->map.data_htp->tping);
    if (file < 0) {
        write(2, "Dialogue is not readable\n", 25);
        game->map.data_htp->str[0] = '\0';
        return;
    }
    if ((len = read(file, game->map.data_htp->str, 300)) < 0) {
        game->map.data_htp->str[0] = '\0';
        return;
    } else {
        game->map.data_htp->str[len] = '\0';
    }
    close(file);
}