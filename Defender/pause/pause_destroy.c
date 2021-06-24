/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** destroy pause scenes
*/

#include "include/defender.h"

void pause_destroy(game_t *main_s)
{
    destroy_object(main_s->menu_pause->dark);
    destroy_object(main_s->menu_pause->plank);
    destroy_object(main_s->menu_pause->rope_1);
    destroy_object(main_s->menu_pause->rope_2);
    destroy_object(main_s->menu_pause->music_bar_bg);
    destroy_object(main_s->menu_pause->music_bar);
    destroy_object(main_s->menu_pause->rate_bar_bg);
    destroy_object(main_s->menu_pause->rate_bar);
    destroy_circle(main_s->menu_pause->music_minus);
    destroy_circle(main_s->menu_pause->music_plus);
    destroy_circle(main_s->menu_pause->rate_minus);
    destroy_circle(main_s->menu_pause->rate_plus);
    destroy_circle(main_s->menu_pause->resume);
    destroy_rect(main_s->menu_pause->menu);
    destroy_rect(main_s->menu_pause->quit);
    destroy_text(main_s->menu_pause->header);
    destroy_text(main_s->menu_pause->music_volume);
    destroy_text(main_s->menu_pause->sound_volume);
}