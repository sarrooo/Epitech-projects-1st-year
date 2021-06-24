/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init sound for win screen
*/

#include "include/defender.h"

void win_screen_sound(game_t *main_s)
{
    char *path;

    if (main_s->map.if_win == 1)
        path = "asset/music/win_sound.ogg";
    else
        path = "asset/music/loose_sound.ogg";
    main_s->win_screen->sound = sfMusic_createFromFile(path);
    sfMusic_setVolume(main_s->win_screen->sound, main_s->volume);
    sfMusic_setLoop(main_s->win_screen->sound, sfFalse);
    sfMusic_play(main_s->win_screen->sound);
}