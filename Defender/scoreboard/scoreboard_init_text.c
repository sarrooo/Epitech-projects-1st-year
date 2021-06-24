/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init text for pause menu
*/

#include "include/defender.h"

void scoreboard_text_3(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.path = "asset/font/Dimbo.ttf";
    info.size.x = 80;
    info.color = sfWhite;
    info.pos.x = ((size_win.x / 2) - 210);
    info.str = "4.   \0";
    if (main_s->scoreboard_point[3] != NULL)
        info.str = str_cat_score("4.    \0", main_s->scoreboard_point[3]);
    info.pos.y = ((size_win.y / 2) + 100);
    init_text(main_s, info, main_s->scoreboard->fourth_place);
    info.str = "5.   \0";
    if (main_s->scoreboard_point[4] != NULL)
        info.str = str_cat_score("5.    \0", main_s->scoreboard_point[4]);
    info.pos.y = ((size_win.y / 2) + 200);
    init_text(main_s, info, main_s->scoreboard->fifth_place);
}

void scoreboard_text_2(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.path = "asset/font/Dimbo.ttf";
    info.size.x = 80;
    info.str = "2.   \0";
    if (main_s->scoreboard_point[1] != NULL)
        info.str = str_cat_score("2.    \0", main_s->scoreboard_point[1]);
    info.pos.x = ((size_win.x / 2) - 210);
    info.pos.y = ((size_win.y / 2) - 100);
    info.color = sfWhite;
    init_text(main_s, info, main_s->scoreboard->second_place);
    info.str = "3.    \0";
    if (main_s->scoreboard_point[2] != NULL)
        info.str = str_cat_score("3.    \0", main_s->scoreboard_point[2]);
    info.pos.x = ((size_win.x / 2) - 210);
    info.pos.y = ((size_win.y / 2) - 0);
    init_text(main_s, info, main_s->scoreboard->third_place);
    scoreboard_text_3(main_s);
}

void scoreboard_text(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    read_scoreboard(main_s);
    info.str = "Scoreboard";
    info.path = "asset/font/Dimbo.ttf";
    info.pos.x = ((size_win.x / 2) - 210);
    info.pos.y = ((size_win.y / 2) - 360);
    info.size.x = 110;
    info.color = sfWhite;
    init_text(main_s, info, main_s->scoreboard->header);
    info.str = "1.    \0";
    if (main_s->scoreboard_point[0] != NULL)
        info.str = str_cat_score("1.    \0", main_s->scoreboard_point[0]);
    info.pos.x = ((size_win.x / 2) - 210);
    info.pos.y = ((size_win.y / 2) - 200);
    info.size.x = 80;
    info.color = sfWhite;
    init_text(main_s, info, main_s->scoreboard->first_place);
    scoreboard_text_2(main_s);
}