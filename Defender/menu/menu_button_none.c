/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** set button to orignal status
*/

#include "include/defender.h"

void menu_check_button_none(game_t *main_s)
{
    animation_rect_none(main_s, main_s->menu_scene->sound_but);
    animation_rect_none(main_s, main_s->menu_scene->music_but);
    animation_rect_none(main_s, main_s->menu_scene->setting_but);
    animation_rect_none(main_s, main_s->menu_scene->htp_but);
    animation_rect_none(main_s, main_s->menu_scene->scoreboard_button);
    animation_circle_none(main_s, main_s->menu_scene->play_but);
    animation_circle_none(main_s, main_s->menu_scene->quit_but);
}