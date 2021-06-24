/*
** EPITECH PROJECT, 2021
** my_defende
** File description:
** init rect button for main menu
*/

#include "include/defender.h"

void menu_music_button(game_t *main_s)
{
    info_t info;

    info.callback = play_stop_music;
    info.size = int_to_sfvector2f(100, 100);
    if (sfMusic_getStatus(main_s->music) == sfPlaying)
        info.path = "asset/button/music_on.png";
    else
        info.path = "asset/button/music_off.png";
    info.pos = int_to_sfvector2f(10, 10);
    rect_button(main_s, info, main_s->menu_scene->music_but);
}

void menu_sound_button(game_t *main_s)
{
    info_t info;

    info.pos = int_to_sfvector2f(110, 10);
    info.size = int_to_sfvector2f(100, 100);
    if (sfMusic_getStatus(main_s->music) == sfPlaying)
        info.path = "asset/button/sound_on.png";
    else
        info.path = "asset/button/sound_off.png";
    info.callback = play_stop_fx;
    rect_button(main_s, info, main_s->menu_scene->sound_but);
}

void menu_rect_button(game_t *main_s)
{
    info_t info;

    menu_music_button(main_s);
    menu_sound_button(main_s);
    info.pos = int_to_sfvector2f(210, 10);
    info.size = int_to_sfvector2f(100, 100);
    info.path = "asset/button/setting.png";
    info.callback = setting_menu;
    rect_button(main_s, info, main_s->menu_scene->setting_but);
    info.callback = htp_menu;
    info.path = "asset/button/htp.png";
    info.pos = int_to_sfvector2f(10, 880);
    info.size = int_to_sfvector2f(276, 125);
    rect_button(main_s, info, main_s->menu_scene->htp_but);
    info.callback = open_scoreboard;
    info.path = "asset/button/button_menu.png";
    info.pos = int_to_sfvector2f(1815, 910);
    info.size = int_to_sfvector2f(100, 100);
    rect_button(main_s, info, main_s->menu_scene->scoreboard_button);
}