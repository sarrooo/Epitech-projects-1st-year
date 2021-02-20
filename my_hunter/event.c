/*
** EPITECH PROJECT, 2020
** event.c
** File description:
** manage event on game
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Config.h>
#include <SFML/Audio.h>
#include "include/my.h"

void manage_mouse_click(sfMouseButtonEvent event)
{
    my_printf("Mouse x=%d y=%d\n", event.x, event.y);
}

sfMouseButtonEvent analyse_events(sfRenderWindow *window, sfEvent even)
{
    sfVector2u size = sfRenderWindow_getSize(window);

    while (sfRenderWindow_pollEvent(window, &even)) {
        if (even.type == sfEvtClosed)
            close_window(window);
        if (even.type == sfEvtMouseButtonPressed && even.type != sfEvtClosed)
            return (even.mouseButton);
    }
}
