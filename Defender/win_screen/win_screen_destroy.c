/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** destroy win screen
*/

#include "include/defender.h"

void destroy_win_screen(game_t *main_s)
{
    destroy_object(main_s->win_screen->background);
    destroy_object(main_s->win_screen->plank);
    destroy_object(main_s->win_screen->header);
    destroy_object(main_s->win_screen->dark);
    destroy_object(main_s->win_screen->bg_star);
    destroy_object(main_s->win_screen->star);
    destroy_rect(main_s->win_screen->menu_button);
    destroy_rect(main_s->win_screen->replay_button);
    destroy_circle(main_s->win_screen->quit_button);
    destroy_text(main_s->win_screen->message_1);
    destroy_text(main_s->win_screen->message_2);
    sfMusic_destroy(main_s->win_screen->sound);
    free(main_s->win_screen);
}