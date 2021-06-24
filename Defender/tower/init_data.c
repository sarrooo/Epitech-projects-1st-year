/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init data towers
*/

#include "../include/defender.h"

void init_default_settings(game_t *game)
{
    game->map.stats->archery1.damage = 25;
    game->map.stats->archery1.attack_speed = 0.70;
    game->map.stats->archery1.range = 300;
    game->map.stats->archery2.damage = 55;
    game->map.stats->archery2.attack_speed = 0.5;
    game->map.stats->archery2.range = 400;
    game->map.stats->magic1.damage = 6;
    game->map.stats->magic1.attack_speed = 1;
    game->map.stats->magic1.range = 350;
    game->map.stats->magic2.damage = 12;
    game->map.stats->magic2.attack_speed = 1;
    game->map.stats->magic2.range = 350;
}

void init_towers_data(game_t *game)
{
    game->map.stats = malloc(sizeof(towers_stat));
    if (read_parser_xml(game, "./config/towers.xml") == 84) {
        init_default_settings(game);
    }
}

int read_next_data_xml(game_t *game, char *data)
{
    static int i = 0;
    char *info = malloc(sizeof(char) * 7);
    int read = 0;
    int count = -1;
    int value = 0;

    for (; data[i] != '\0'; i++, count = (read == 1) ? count += 1 : count) {
        if (read == 1 && (data[i] < '0' || data[i] > '9')) {
            info[count] = '\0';
            value = my_getnbr(info);
            free(info);
            return (value);
        }
        if (read == 1)
            info[count] = data[i];
        if (data[i] == '=') {
            read = 1;
        }
    }
    free(info);
    return (-1);
}

int init_xml_settings(game_t *game, char *data)
{
    game->map.stats->archery1.damage = read_next_data_xml(game, data);
    game->map.stats->archery1.attack_speed = 0.7;
    game->map.stats->archery1.range = read_next_data_xml(game, data);
    game->map.stats->archery2.damage = read_next_data_xml(game, data);
    game->map.stats->archery2.attack_speed = 0.5;
    game->map.stats->archery2.range = read_next_data_xml(game, data);
    game->map.stats->magic1.damage = read_next_data_xml(game, data);
    game->map.stats->magic1.attack_speed = 1;
    game->map.stats->magic1.range = read_next_data_xml(game, data);
    game->map.stats->magic2.damage = read_next_data_xml(game, data);
    game->map.stats->magic2.attack_speed = 1;
    game->map.stats->magic2.range = read_next_data_xml(game, data);
    check_integrity_of_data(game);
}

int read_parser_xml(game_t *game, char *filepath)
{
    int file = open(filepath, O_RDONLY);
    char *data = malloc(sizeof(char) * 301);
    int len;

    if (file < 0) {
        write(2, "Towers XML is not readable.\n", 28);
        free(data);
        return (84);
    }
    if ((len = read(file, data, 300)) < 0) {
        free(data);
        return (84);
    } else {
        data[len] = '\0';
        if (init_xml_settings(game, data) == 84) {
            free(data);
            return (84);
        }
    }
    free(data);
    return (0);
}