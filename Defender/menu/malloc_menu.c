/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** malloc main menu
*/

#include "include/defender.h"

void malloc_menu(game_t *main_s)
{
    main_s->menu_scene = malloc(sizeof(menu_t));
    main_s->menu_scene->background = malloc(sizeof(object_t));
    main_s->menu_scene->logo = malloc(sizeof(object_t));
    main_s->menu_scene->play_but = malloc(sizeof(circle_but));
    main_s->menu_scene->quit_but = malloc(sizeof(circle_but));
    main_s->menu_scene->sound_but = malloc(sizeof(rect_but));
    main_s->menu_scene->music_but = malloc(sizeof(rect_but));
    main_s->menu_scene->setting_but = malloc(sizeof(rect_but));
    main_s->menu_scene->htp_but = malloc(sizeof(rect_but));
    main_s->menu_scene->scoreboard_button = malloc(sizeof(rect_but));
}