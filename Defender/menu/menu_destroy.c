/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** destroy menu scene
*/

#include "include/defender.h"

void menu_destroy(game_t *main_s)
{
    destroy_rect(main_s->menu_scene->music_but);
    destroy_rect(main_s->menu_scene->sound_but);
    destroy_rect(main_s->menu_scene->setting_but);
    destroy_rect(main_s->menu_scene->htp_but);
    destroy_circle(main_s->menu_scene->play_but);
    destroy_circle(main_s->menu_scene->quit_but);
    destroy_object(main_s->menu_scene->background);
    destroy_object(main_s->menu_scene->logo);
    free(main_s->menu_scene);
}