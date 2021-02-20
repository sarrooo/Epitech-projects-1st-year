/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** start game
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <time.h>
#include "lib/my.h"
#include "include/my.h"
#include <stdio.h>

int click_play(int *click, sfVector2f pS, sfVector2u x, sfVector2f s_p)
{
    if (click[0] <= pS.x + (x.x * s_p.x) && click[0] >= pS.x)
        if (click[1] <= pS.y + (x.y * s_p.y) && click[1] >= pS.y)
            return (1);
    return 0;
}

int menu_play(sfRenderWindow *win, sfSprite *back, sfEvent event)
{
    sfSprite *button = play(win);
    sfVector2f pS = sfSprite_getPosition(button);
    sfVector2f s_p = sfSprite_getScale(button);
    sfVector2u x = sfTexture_getSize(sfSprite_getTexture(button));
    int *click = click_end(win, event);

    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_drawSprite(win, back, NULL);
        sfRenderWindow_drawSprite(win, button, NULL);
        text_start(win);
        click = click_end(win, event);
        if (click_play(click, pS, x, s_p) == 1)
            return (1);
        sfRenderWindow_display(win);
    }
    return (0);
}

int det_option(sfRenderWindow *window, int ac, char **av)
{
    if (!window || ac != 1) {
        if (my_strcmp(av[1], "-h") == 0)
            description();
        return (1);
    }
    return 0;
}
