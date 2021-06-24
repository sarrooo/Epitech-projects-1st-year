/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init text for win screen
*/

#include "include/defender.h"

void win_screen_text_2(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    if (main_s->map.if_win == 1)
        info.str = "Level Complete";
    else
        info.str = "   Level Failed";
    info.path = "asset/font/Dimbo.ttf";
    info.pos.x = ((size_win.x / 2) - (240 * 0.95)) + 85;
    info.pos.y = ((size_win.y / 2) - (266 * 0.95)) + 350;
    info.size.x = 60;
    info.color = sfWhite;
    init_text(main_s, info, main_s->win_screen->message_2);
}

void win_screen_your_score(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;
    int score;

    score = main_s->point_life * 100;
    score = score + main_s->gold_point;
    if (main_s->map.if_win == 2)
        score -= 1000;
    info.color = sfWhite;
    info.path = "asset/font/Dimbo.ttf";
    info.pos.y = 700;
    info.size.x = 40;
    info.pos.x = ((size_win.x / 2) - (240 * 0.95)) + 110;
    info.str = str_cat_score("Your Score:  ", str_int(score));
    init_text(main_s, info, main_s->win_screen->score_txt);
}

void win_screen_text(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;
    int score;

    score = main_s->point_life * 100;
    score = score + main_s->gold_point;
    if (main_s->map.if_win == 1)
        info.str = "Congratulations!";
    else
        info.str = "        Sorry :(";
    info.path = "asset/font/Dimbo.ttf";
    info.pos.x = ((size_win.x / 2) - (240 * 0.95)) + 40;
    info.pos.y = ((size_win.y / 2) - (266 * 0.95)) + 270;
    info.size.x = 70;
    info.color = sfWhite;
    init_text(main_s, info, main_s->win_screen->message_1);
    win_screen_your_score(main_s);
    win_screen_text_2(main_s);
    win_screen_scoreboard_text(main_s);
}