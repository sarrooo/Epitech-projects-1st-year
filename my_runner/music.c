/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** manage music
*/

#include "include/my.h"

sfMusic *back_sound(void)
{
    sfMusic *music = sfMusic_createFromFile("music/manege.wav");

    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, 20);
    sfMusic_play(music);
    return (music);
}

sfMusic *jump_sound(void)
{
    sfMusic *music = sfMusic_createFromFile("music/jump.wav");

    sfMusic_setLoop(music, sfFalse);
    sfMusic_setVolume(music, 40);
    return (music);
}

sfSprite *manage_click_music(list *l_a, sfEvent event, sfSprite *button)
{
    sfTexture *texture;
    sfVector2f size;

    if (sfMusic_getStatus(l_a->music) == sfPlaying) {
        sfMusic_pause(l_a->music);
        sfMusic_setVolume(l_a->jump_fx, 0);
        texture = sfTexture_createFromFile("button/sound_off.png", NULL);
    }
    else {
        sfMusic_play(l_a->music);
        sfMusic_setVolume(l_a->jump_fx, 40);
        texture = sfTexture_createFromFile("button/sound.png", NULL);
    }
    size.x = 0.4;
    size.y = 0.4;
    sfSprite_setScale(button, size);
    sfTexture_setSmooth(texture, sfTrue);
    sfSprite_setTexture(button, texture, sfTrue);
}