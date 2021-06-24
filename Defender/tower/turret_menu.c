/*
** EPITECH PROJECT, 2021
** defender
** File description:
** turret
*/

#include "../include/defender.h"

void destroy_turret_menu(game_t *game)
{
    for (int i = 0; i < 7; i += 1) {
        if (game->map.towers[i].type != 0)
            destroy_tower(game, i);
    }
    free(game->map.towers);
    sfSprite_destroy(game->map.turret_menu.sprite);
    sfTexture_destroy(game->map.turret_menu.texture);
    sfSprite_destroy(game->map.turret_menu.sell);
    sfTexture_destroy(game->map.turret_menu.t_sell);
}

void display_buy_menu(game_t *game)
{
    if (game->map.turret_menu.clicked > 0)
        sfRenderWindow_drawSprite(game->win,
        game->map.turret_menu.sprite, NULL);
}

void display_turret_menu(game_t *game)
{
    for (int i = 0; i < 7; i += 1) {
        if ((game->mouse_pos.x > game->map.turret_pos[i].x1 &&
        game->mouse_pos.x < game->map.turret_pos[i].x2) &&
        (game->mouse_pos.y > game->map.turret_pos[i].y1 &&
        game->mouse_pos.y < game->map.turret_pos[i].y2) &&
        game->map.towers[i].type == 0) {
            game->map.turret_menu.position.x = game->map.turret_pos[i].x1 - 40;
            if (game->map.turret_pos[i].y1 > 800)
                game->map.turret_menu.position.y = 800;
            else
                game->map.turret_menu.position.y =
                game->map.turret_pos[i].y1 - 60;
            sfSprite_setPosition(game->map.turret_menu.sprite,
            game->map.turret_menu.position);
            game->map.turret_menu.clicked = i + 1;
        }
    }
    return;
}

void choice_turret2(game_t *game, sfVector2f posT, sfVector2f pos, int i)
{
    if (game->mouse_pos.x > posT.x + 150 && game->mouse_pos.x < posT.x + 230
    && game->mouse_pos.y > posT.y + 35 && game->mouse_pos.y < posT.y + 100 &&
        game->map.data->points_gold >= 250)
        init_archery_2(game, game->map.turret_menu.clicked - 1,
        (sfVector2f){pos.x - 65, pos.y - 90});
    if (game->mouse_pos.x > posT.x + 150 && game->mouse_pos.x < posT.x + 230
    && game->mouse_pos.y > posT.y + 160 && game->mouse_pos.y < posT.y + 240 &&
        game->map.data->points_gold >= 250)
        init_magic_2(game, game->map.turret_menu.clicked - 1,
        (sfVector2f){pos.x - 15, pos.y - 90});
}

void choice_turret(game_t *game)
{
    sfVector2f posT;
    int i = game->map.turret_menu.clicked - 1;
    sfVector2f pos;

    if (game->map.turret_menu.clicked > 0) {
        pos = (sfVector2f) {game->map.turret_pos[i].x1,
        game->map.turret_pos[i].y1 - 50};
        posT = sfSprite_getPosition(game->map.turret_menu.sprite);
        if (game->mouse_pos.x > posT.x && game->mouse_pos.x < posT.x + 80 &&
        game->mouse_pos.y > posT.y + 35 && game->mouse_pos.y < posT.y + 100 &&
        game->map.data->points_gold >= 100)
            init_archery_1(game, game->map.turret_menu.clicked - 1,
            (sfVector2f){pos.x - 50, pos.y - 75});
        if (game->mouse_pos.x > posT.x && game->mouse_pos.x < posT.x + 80 &&
        game->mouse_pos.y > posT.y + 160 && game->mouse_pos.y < posT.y + 240 &&
        game->map.data->points_gold >= 100)
            init_magic_1(game, game->map.turret_menu.clicked - 1,
            (sfVector2f){pos.x - 15, pos.y - 80});
        choice_turret2(game, posT, pos, i);
    }
}