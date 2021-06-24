/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** function for setting volume button
*/

#include "include/defender.h"

void raise_music_volume(game_t *main_s)
{
    float volume = sfMusic_getVolume(main_s->music);
    int new_volume;

    animation_circle_clic(main_s, *main_s->menu_setting->music_plus);
    if (volume < 20) {
        new_volume = (int)volume + 2;
        if (volume > 18)
            sfMusic_setVolume(main_s->music, 20);
        else
            sfMusic_setVolume(main_s->music, new_volume);
    }
}

void reduce_music_volume(game_t *main_s)
{
    float volume = sfMusic_getVolume(main_s->music);

    animation_circle_clic(main_s, *main_s->menu_setting->music_minus);
    if (volume > 0) {
        if (volume < 2)
            sfMusic_setVolume(main_s->music, 0);
        else
            sfMusic_setVolume(main_s->music, volume - 2.0);
    }
}