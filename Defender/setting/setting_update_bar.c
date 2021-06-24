/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** manage bar for setting
*/

#include "include/defender.h"

void rect_music_bar(sfMusic *music, object_t *bar)
{
    float volume = sfMusic_getVolume(music);
    sfIntRect rect;

    rect.height = 35;
    rect.width= (int)volume * 212 / 20;
    rect.top = 0;
    rect.left = 0;
    sfSprite_setTextureRect(bar->sprite, rect);
}

void rect_rate_bar(game_t *main_s, object_t *bar)
{
    sfIntRect rect;

    rect.height = 35;
    rect.width= (int)main_s->framerate * 212 / 120;
    rect.top = 0;
    rect.left = 0;
    sfSprite_setTextureRect(bar->sprite, rect);
}

void rect_sound_bar(game_t *main_s, object_t *bar)
{
    float volume = main_s->volume;
    sfIntRect rect;

    rect.height = 35;
    rect.width= (int)volume * 212 / 100;
    rect.top = 0;
    rect.left = 0;
    sfSprite_setTextureRect(bar->sprite, rect);
}