/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** handler for menu and setting
*/

#include "include/defender.h"

void handler_menu(game_t *main_s)
{
    check_menu_event(main_s);
    draw_menu(main_s);
}

void handler_setting(game_t *main_s)
{
    check_setting_event(main_s);
    rect_music_bar(main_s->music, main_s->menu_setting->music_bar);
    rect_rate_bar(main_s, main_s->menu_setting->rate_bar);
    draw_setting(main_s);
}

void handler_pause(game_t *main_s, int on)
{
    check_pause_event(main_s, on);
    rect_music_bar(main_s->music, main_s->menu_pause->music_bar);
    rect_sound_bar(main_s, main_s->menu_pause->rate_bar);
    draw_pause(main_s);
}

void handler_win_screen(game_t *main_s)
{
    check_win_screen_event(main_s);
    draw_win_screen(main_s);
}

void handler_scoreboard(game_t *main_s)
{
    check_scoreboard_event(main_s);
    draw_scoreboard(main_s);
}