/*
** EPITECH PROJECT, 2021
** my_defende
** File description:
** init music for main menu
*/

#include "include/defender.h"

void init_music(game_t *main_s)
{
    char path[] = "asset/music/main_menu.ogg";

    main_s->music = sfMusic_createFromFile(path);
    sfMusic_setLoop(main_s->music, sfTrue);
    sfMusic_setVolume(main_s->music, 10);
    sfMusic_play(main_s->music);
}