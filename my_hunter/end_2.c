/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** end_game
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

void finish_game(sfRenderWindow *win, sfSprite *back, sfMusic *m)
{
    sfMusic_destroy(m);
    sfRenderWindow_destroy(win);
    sfSprite_destroy(back);
}

int error(sfRenderWindow *window, int ac, char **av, sfMusic *s)
{
    if (det_option(window, ac, av) == 1) {
        sfMusic_destroy(s);
        sfRenderWindow_destroy(window);
        return (84);
    }
    return (0);
}
