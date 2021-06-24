/*
** EPITECH PROJECT, 2021
** my_defende 
** File description:
** malloc  win screen
*/

#include "include/defender.h"

void malloc_win_screen(game_t *main_s)
{
    main_s->win_screen = malloc(sizeof(win_screen_t));
    main_s->win_screen->background = malloc(sizeof(object_t));
    main_s->win_screen->plank = malloc(sizeof(object_t));
    main_s->win_screen->header = malloc(sizeof(object_t));
    main_s->win_screen->dark = malloc(sizeof(object_t));
    main_s->win_screen->star = malloc(sizeof(object_t));
    main_s->win_screen->bg_star = malloc(sizeof(object_t));
    main_s->win_screen->menu_button = malloc(sizeof(rect_but));
    main_s->win_screen->replay_button = malloc(sizeof(rect_but));
    main_s->win_screen->quit_button = malloc(sizeof(circle_but));
    main_s->win_screen->message_1 = malloc(sizeof(text_t));
    main_s->win_screen->message_2 = malloc(sizeof(text_t));
    main_s->win_screen->plank_scoreboard = malloc(sizeof(object_t));
    main_s->win_screen->header_scoreboard = malloc(sizeof(text_t));
    main_s->win_screen->first_place = malloc(sizeof(text_t));
    main_s->win_screen->second_place = malloc(sizeof(text_t));
    main_s->win_screen->third_place = malloc(sizeof(text_t));
    main_s->win_screen->fourth_place = malloc(sizeof(text_t));
    main_s->win_screen->fifth_place = malloc(sizeof(text_t));
    main_s->win_screen->score_txt = malloc(sizeof(text_t));
}