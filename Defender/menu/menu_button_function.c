/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** callback of music button
*/

#include "include/defender.h"

void close_window(game_t *main_s)
{
    animation_circle_clic(main_s, *main_s->menu_scene->quit_but);
    sfRenderWindow_close(main_s->win);
}

void open_scoreboard(game_t *main_s)
{
    animation_rect_clic(main_s, *main_s->menu_scene->scoreboard_button);
    main_s->current_scene = 7;
    main_s->scene_config = &init_scoreboard;
}

void play_game(game_t *main_s)
{
    animation_circle_clic(main_s, *main_s->menu_scene->play_but);
    main_s->current_scene = MAP1;
    main_s->scene_config = &game_config_first_map;
}

void setting_menu(game_t *main_s)
{
    animation_rect_clic(main_s, *main_s->menu_scene->setting_but);
    main_s->current_scene = SETTINGS;
    main_s->scene_config = &init_setting_scenes;
}

void htp_menu(game_t *main_s)
{
    animation_rect_clic(main_s, *main_s->menu_scene->htp_but);
    main_s->current_scene = 7;
    main_s->scene_config = &game_config_htp;
}