/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** function for setting button
*/

#include "include/defender.h"

void reduce_framerate(game_t *main_s)
{
    animation_circle_clic(main_s, *main_s->menu_setting->rate_minus);
    if (main_s->framerate > 30) {
        sfRenderWindow_setFramerateLimit(main_s->win, main_s->framerate - 30);
        main_s->framerate = main_s->framerate - 30;
    }
}

void raise_framerate(game_t *main_s)
{
    animation_circle_clic(main_s, *main_s->menu_setting->rate_plus);
    if (main_s->framerate < 120) {
        sfRenderWindow_setFramerateLimit(main_s->win, main_s->framerate + 30);
        main_s->framerate = main_s->framerate + 30;
    }
}