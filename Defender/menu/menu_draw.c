/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** draw scenes
*/

#include "include/defender.h"

void draw_menu(game_t *main_s)
{
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_scene->background->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_scene->logo->sprite, NULL);
    sfRenderWindow_drawCircleShape(main_s->win,
    main_s->menu_scene->play_but->button, NULL);
    sfRenderWindow_drawCircleShape(main_s->win,
    main_s->menu_scene->quit_but->button, NULL);
    sfRenderWindow_drawRectangleShape(main_s->win,
    main_s->menu_scene->sound_but->button, NULL);
    sfRenderWindow_drawRectangleShape(main_s->win,
    main_s->menu_scene->music_but->button, NULL);
    sfRenderWindow_drawRectangleShape(main_s->win,
    main_s->menu_scene->setting_but->button, NULL);
    sfRenderWindow_drawRectangleShape(main_s->win,
    main_s->menu_scene->htp_but->button, NULL);
    sfRenderWindow_drawRectangleShape(main_s->win,
    main_s->menu_scene->scoreboard_button->button, NULL);
}