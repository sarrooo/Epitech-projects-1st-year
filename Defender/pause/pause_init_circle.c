/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init circle button for menu pause
*/

#include "include/defender.h"

void init_pause_music(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.callback = reduce_music_volume_pause;
    info.radian = 25;
    info.path = "asset/button/button_minus.png";
    info.pos.x = ((size_win.x / 2) - 110) + 140;
    info.pos.y = ((size_win.y / 2) - 23) - 70;
    circle_button(main_s, info, main_s->menu_pause->music_minus);
    info.callback = raise_music_volume_pause;
    info.path = "asset/button/button_plus.png";
    info.pos.x = ((size_win.x / 2) - 110) + 375;
    circle_button(main_s, info, main_s->menu_pause->music_plus);
}

void init_pause_rate(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.radian = 25;
    info.callback = reduce_sound_volume_pause;
    info.path = "asset/button/button_minus.png";
    info.pos.x = ((size_win.x / 2) - 110) - 195;
    info.pos.y = ((size_win.y / 2) - 23) - 70;
    circle_button(main_s, info, main_s->menu_pause->rate_minus);
    info.callback = raise_sound_volume_pause;
    info.path = "asset/button/button_plus.png";
    info.pos.x = ((size_win.x / 2) - 110) + 40;
    circle_button(main_s, info, main_s->menu_pause->rate_plus);
}

void pause_circle_button(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.callback = resume_game;
    info.radian = 90;
    info.path = "asset/button/play.png";
    info.pos.x = (size_win.x / 2) - 90;
    info.pos.y = (size_win.y / 2) - 90 + 65;
    circle_button(main_s, info, main_s->menu_pause->resume);
    init_pause_rate(main_s);
    init_pause_music(main_s);
}
