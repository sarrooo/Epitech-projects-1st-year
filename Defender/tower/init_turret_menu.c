/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init turret menu
*/

#include "../include/defender.h"

void init_turret_menu(game_t *game)
{
    game->map.turret_menu.sprite = sfSprite_create();
    game->map.turret_menu.texture =
    sfTexture_createFromFile("./asset/choice.png", NULL);
    sfSprite_setTexture(game->map.turret_menu.sprite,
    game->map.turret_menu.texture, sfTrue);
    game->map.turret_menu.position = (sfVector2f){0, 0};
    game->map.turret_menu.clicked = 0;
    game->map.turret_menu.sell = sfSprite_create();
    game->map.turret_menu.t_sell =
    sfTexture_createFromFile("./asset/sell.png", NULL);
    sfSprite_setTexture(game->map.turret_menu.sell,
    game->map.turret_menu.t_sell, sfTrue);
    game->map.turret_menu.sell_clicked = 0;
}