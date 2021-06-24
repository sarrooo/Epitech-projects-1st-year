/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defense
*/

#include "../include/defender.h"

void load_map1_pos(game_t *game)
{
    char path[7][50] = {"asset/map1pos/pos1.png", "asset/map1pos/pos2.png",
    "asset/map1pos/pos3.png", "asset/map1pos/pos4.png",
    "asset/map1pos/pos5.png", "asset/map1pos/pos6.png",
    "asset/map1pos/pos7.png"};
    int x1_list[] = {60, 455, 1155, 1495, 1565, 1495, 800};
    int x2_list[] = {260, 655, 1360, 1700, 1770, 1695, 1000};
    int y1_list[] = {625, 600, 550, 930, 600, 250, 245};
    int y2_list[] = {775, 750, 675, 1080, 750, 380, 385};

    for (int i = 0; i < 7; i++) {
        game->map.turret_pos[i].x1 = x1_list[i];
        game->map.turret_pos[i].x2 = x2_list[i];
        game->map.turret_pos[i].y1 = y1_list[i];
        game->map.turret_pos[i].y2 = y2_list[i];
        game->map.turret_pos[i].texture =
        sfTexture_createFromFile(path[i], NULL);
        game->map.turret_pos[i].sprite = sfSprite_create();
        sfSprite_setTexture(game->map.turret_pos[i].sprite,
        game->map.turret_pos[i].texture, sfTrue);
    }
}

void destroy_hover_effects(game_t *game)
{
    for (int i = 0; i < 7; i += 1) {
        sfSprite_destroy(game->map.turret_pos[i].sprite);
        sfTexture_destroy(game->map.turret_pos[i].texture);
    }
    free(game->map.turret_pos);
}

void load_hover_effects(game_t *game)
{
    game->map.turret_pos = malloc(sizeof(turret_pos_t) * 7);
    load_map1_pos(game);
}