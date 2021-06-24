/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** function for sound button
*/

#include "include/defender.h"

void raise_sound_volume_pause(game_t *main_s)
{
    float volume = main_s->volume;

    animation_circle_clic(main_s, *main_s->menu_pause->rate_plus);
    if (volume < 100) {
        if (volume > 98)
            main_s->volume = 100;
        else
            main_s->volume += 10;
    }
}

void reduce_sound_volume_pause(game_t *main_s)
{
    float volume = main_s->volume;

    animation_circle_clic(main_s, *main_s->menu_pause->rate_minus);
    if (volume > 0) {
        if (volume < 10)
            main_s->volume = 0;
        else
            main_s->volume -= 10;
    }
}