/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** launch menu
*/

#include "include/my.h"

int launch_menu(list *l_a, sfEvent event)
{
    sfSprite *play = draw_play(l_a->win);
    sfSprite *music = draw_music(l_a->win, l_a->music);
    int *click = click_pos(l_a->win, event);

    l_a->music_but->sprite = music;
    while (sfRenderWindow_isOpen(l_a->win)) {
        draw_par(l_a->win, l_a->par);
        text_start(l_a->win);
        sfRenderWindow_drawSprite(l_a->win, play, NULL);
        sfRenderWindow_drawSprite(l_a->win, music, NULL);
        click = click_pos(l_a->win, event);
        if (click_ok_play(l_a, event, play, click) == 1)
            return (1);
        if (click_ok(l_a, event, music, click) == 1)
            manage_click_music(l_a, event, music);
        sfRenderWindow_display(l_a->win);
    }
}
