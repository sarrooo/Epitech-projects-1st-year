/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** music
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>
#include "lib/my.h"
#include "include/my.h"
#include <stdio.h>

sfMusic *back_sound(void)
{
    sfMusic *music = sfMusic_createFromFile("music/bird.wav");

    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, 50);
    sfMusic_play(music);
    return (music);
}

sfMusic *shoot_sound(void)
{
    sfMusic *music = sfMusic_createFromFile("music/shoot.wav");

    sfMusic_setVolume(music, 30);
    return (music);
}
