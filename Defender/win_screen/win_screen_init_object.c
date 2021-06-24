/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init object for win screen
*/

#include "include/defender.h"

void win_screen_scoreboard_object(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.scale = (sfVector2f){0.5, 0.5};
    info.path = "asset/bg/table_big.png";
    info.pos.x = 1580;
    info.pos.y = 600;
    init_object(main_s, info, main_s->win_screen->plank_scoreboard);
}

void win_screen_star(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;
    int point_life = main_s->point_life;

    info.path = "asset/window.png";
    info.scale = (sfVector2f){0.95, 0.95};
    info.pos.x = ((size_win.x / 2) - (240 * 0.95));
    info.pos.y = ((size_win.y / 2) - (266 * 0.95)) + 15;
    init_object(main_s, info, main_s->win_screen->bg_star);
    if (main_s->map.if_win == 1)
        if (point_life >= 15)
            info.path = "asset/star/star_4.png";
        else if (point_life <= 15 && point_life >= 10)
            info.path = "asset/star/star_3.png";
        else
            info.path = "asset/star/star_2.png";
    else
        info.path = "asset/star/star_1.png";
    info.pos.x = ((size_win.x / 2) - (216 * 0.95));
    info.pos.y = ((size_win.y / 2) - (119 * 0.95)) - 110;
    init_object(main_s, info, main_s->win_screen->star);
}

void win_screen_object(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.scale = (sfVector2f){1, 1};
    info.path = "asset/bg/dark.png";
    info.pos = (sfVector2f){0, 0};
    init_object(main_s, info, main_s->win_screen->dark);
    info.path = "asset/bg/bg.png";
    init_object(main_s, info, main_s->win_screen->background);
    info.path = "asset/bg/table_big.png";
    info.pos.x = ((size_win.x / 2) - (319 * 1));
    info.pos.y = (size_win.y / 2) - (400 * 1);
    init_object(main_s, info, main_s->win_screen->plank);
    if (main_s->map.if_win == 1)
        info.path = "asset/logo/header_win.png";
    else
        info.path = "asset/logo/header_failed.png";
    info.pos.x = ((size_win.x / 2) - 197);
    info.pos.y = ((size_win.y / 2) - 230) - 170;
    init_object(main_s, info, main_s->win_screen->header);
    win_screen_star(main_s);
}