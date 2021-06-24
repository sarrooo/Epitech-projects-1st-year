/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init text for scoreboard for win screen
*/

#include "include/defender.h"

void win_screen_scoreboard_text_3(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.path = "asset/font/Dimbo.ttf";
    info.size.x = 35;
    info.pos.x = 1640;
    info.color = sfWhite;
    info.str = "5.   \0";
    if (main_s->scoreboard_point[4] != NULL)
        info.str = str_cat_score("5.    \0", main_s->scoreboard_point[4]);
    info.pos.y = 890;
    init_text(main_s, info, main_s->win_screen->fifth_place);
}

void win_screen_scoreboard_text_2(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.path = "asset/font/Dimbo.ttf";
    info.size.x = 35;
    info.pos.x = 1640;
    info.str = "3.    \0";
    if (main_s->scoreboard_point[2] != NULL)
        info.str = str_cat_score("3.    \0", main_s->scoreboard_point[2]);
    info.pos.y = 790;
    info.color = sfWhite;
    init_text(main_s, info, main_s->win_screen->third_place);
    info.str = "4.   \0";
    if (main_s->scoreboard_point[3] != NULL)
        info.str = str_cat_score("4.    \0", main_s->scoreboard_point[3]);
    info.pos.y = 840;
    init_text(main_s, info, main_s->win_screen->fourth_place);
    win_screen_scoreboard_text_3(main_s);
}

void win_screen_scoreboard_text(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.path = "asset/font/Dimbo.ttf";
    info.str = "Scoreboard";
    info.pos = (sfVector2f){1640, 620};
    info.size.x = 50;
    info.color = sfWhite;
    init_text(main_s, info, main_s->win_screen->header_scoreboard);
    info.str = "1.    \0";
    if (main_s->scoreboard_point[0] != NULL)
        info.str = str_cat_score("1.    \0", main_s->scoreboard_point[0]);
    info.size.x = 35;
    info.pos = (sfVector2f){1640, 690};
    init_text(main_s, info, main_s->win_screen->first_place);
    info.str = "2.   \0";
    if (main_s->scoreboard_point[1] != NULL)
        info.str = str_cat_score("2.    \0", main_s->scoreboard_point[1]);
    info.pos.y = 740;
    init_text(main_s, info, main_s->win_screen->second_place);
    win_screen_scoreboard_text_2(main_s);
}