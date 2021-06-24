/*
** EPITECH PROJECT, 2021
** defender
** File description:
** turret
*/

#include "../include/defender.h"

void display_menu_sell(game_t *game)
{
    if (game->map.turret_menu.sell_clicked > 0)
        sfRenderWindow_drawSprite(game->win,
        game->map.turret_menu.sell, NULL);
}

void display_sell_menu(game_t *game)
{
    for (int i = 0; i < 7; i += 1) {
        if ((game->mouse_pos.x > game->map.turret_pos[i].x1 &&
        game->mouse_pos.x < game->map.turret_pos[i].x2) &&
        (game->mouse_pos.y > game->map.turret_pos[i].y1 &&
        game->mouse_pos.y < game->map.turret_pos[i].y2) &&
        game->map.towers[i].type != 0) {
            game->map.turret_menu.position.x = game->map.turret_pos[i].x1 - 50;
            if (game->map.turret_pos[i].y1 > 800)
                game->map.turret_menu.position.y = 800;
            else
                game->map.turret_menu.position.y =
                game->map.turret_pos[i].y1 - 90;
            sfSprite_setPosition(game->map.turret_menu.sell,
            game->map.turret_menu.position);
            game->map.turret_menu.sell_clicked = i + 1;
        }
    }
    return;
}

void get_money(game_t *game, int i)
{
    if (game->map.towers[i].type == ARCHER_1 ||
    game->map.towers[i].type == MAGICIAN_1) {
        game->map.data->points_gold += 75;
    }
    if (game->map.towers[i].type == ARCHER_2 ||
    game->map.towers[i].type == MAGICIAN_2) {
        game->map.data->points_gold += 200;
    }
}

int choose_action(game_t *game)
{
    sfVector2f psT;
    int i = game->map.turret_menu.sell_clicked -1;
    sfVector2f pos;

    if (game->map.turret_menu.sell_clicked > 0) {
        pos = (sfVector2f) {game->map.turret_pos[i].x1,
        game->map.turret_pos->y1};
        psT = sfSprite_getPosition(game->map.turret_menu.sell);
        if (game->mouse_pos.x > psT.x + 10 && game->mouse_pos.x < psT.x + 90
        && game->mouse_pos.y > psT.y + 60 && game->mouse_pos.y < psT.y + 150) {
            get_money(game, i);
            destroy_tower(game, i);
            return (1);
        }
    }
    return (0);
}