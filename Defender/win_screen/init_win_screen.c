/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init win screen
*/

#include "include/defender.h"

void init_win_screen_scenes(game_t *main_s)
{
    malloc_win_screen(main_s);
    score_win_screen(main_s);
    win_screen_object(main_s);
    win_screen_sound(main_s);
    win_screen_rect_button(main_s);
    win_screen_circle_button(main_s);
    win_screen_text(main_s);
    win_screen_scoreboard_object(main_s);
    win_screen_scoreboard_text(main_s);
    main_s->ex_scene = 6;
    main_s->handler_scene = &handler_win_screen;
    main_s->scene_destroy = &destroy_win_screen;
}