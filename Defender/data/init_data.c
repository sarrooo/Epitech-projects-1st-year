/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init_data
*/

#include "../include/defender.h"

void set_text(game_t *game)
{
    char *life = malloc(sizeof(char) * 3);
    char *current_wave = malloc(sizeof(char) * 15);
    char *max_wave = malloc(sizeof(char) * 3);
    char *gold = malloc(sizeof(char) * 7);

    life = str_int(game->map.data->points_life);
    current_wave = str_int(game->map.data->points_wave);
    max_wave = str_int(game->map.data->wave_max);
    gold = str_int(game->map.data->points_gold);
    my_strcat(current_wave, "/");
    my_strcat(current_wave, max_wave);
    sfText_setString(game->map.data->wave, current_wave);
    sfText_setString(game->map.data->life, life);
    sfText_setString(game->map.data->gold, gold);
    free(life);
    free(current_wave);
    free(max_wave);
    free(gold);
}

void config_text(game_t *game)
{
    set_text(game);
    sfSprite_setScale(game->map.data->s_gold, (sfVector2f){1.3, 1.3});
    sfSprite_setScale(game->map.data->s_wave, (sfVector2f){1.3, 1.3});
    sfText_setFont(game->map.data->wave, game->map.data->font);
    sfText_setFont(game->map.data->life, game->map.data->font);
    sfText_setFont(game->map.data->gold, game->map.data->font);
    sfText_setColor(game->map.data->wave, sfWhite);
    sfText_setColor(game->map.data->life, sfWhite);
    sfText_setColor(game->map.data->gold, sfWhite);
    sfText_setPosition(game->map.data->wave, (sfVector2f){210, 70});
    sfText_setPosition(game->map.data->life, (sfVector2f){170, 20});
    sfText_setPosition(game->map.data->gold, (sfVector2f){250, 20});
}

void init_data_points(game_t *game)
{
    game->map.data->points_gold = 200;
    game->map.data->points_life = 20;
    game->map.data->points_wave = 1;
    game->map.data->life_max = 20;
    game->map.data->wave_max = 10;
    game->map.data->start_gold = 200;
}

void init_data(game_t *game)
{
    game->map.data = malloc(sizeof(data_t));
    init_data_points(game);
    game->map.data->s_gold = sfSprite_create();
    game->map.data->s_wave = sfSprite_create();
    game->map.data->t_gold =
    sfTexture_createFromFile("./asset/gold.png", NULL);
    game->map.data->t_wave =
    sfTexture_createFromFile("./asset/wave.png", NULL);
    sfSprite_setTexture(game->map.data->s_gold,
    game->map.data->t_gold, sfTrue);
    sfSprite_setTexture(game->map.data->s_wave,
    game->map.data->t_wave, sfTrue);
    sfSprite_setPosition(game->map.data->s_gold, (sfVector2f){110, 10});
    sfSprite_setPosition(game->map.data->s_wave, (sfVector2f){130, 62});
    game->map.data->font = sfFont_createFromFile("./asset/font/Dimbo.ttf");
    game->map.data->gold = sfText_create();
    game->map.data->life = sfText_create();
    game->map.data->wave = sfText_create();
    config_text(game);
    set_text(game);
}