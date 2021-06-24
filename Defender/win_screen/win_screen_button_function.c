/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** function for button on win screen
*/

#include "include/defender.h"

void return_to_menu(game_t *main_s)
{
    animation_rect_clic(main_s, *main_s->win_screen->menu_button);
    main_s->current_scene = 1;
    main_s->scene_config = &init_menu_scenes;
}

void restart_game(game_t *main_s)
{
    animation_rect_clic(main_s, *main_s->win_screen->replay_button);
    main_s->current_scene = 3;
    main_s->scene_config = &game_config_first_map;
}

void close_window_win_screen(game_t *main_s)
{
    animation_circle_clic(main_s, *main_s->win_screen->quit_button);
    sfRenderWindow_close(main_s->win);
}