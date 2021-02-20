/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** end games
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <time.h>
#include "lib/my.h"
#include "include/my.h"
#include <stdio.h>

int replay_game(sfRenderWindow *win, int *score, sfEvent event, int *click)
{
    sfSprite *button = replay(win);
    sfVector2f pS = sfSprite_getPosition(button);
    sfVector2f s_p = sfSprite_getScale(button);
    sfVector2u x = sfTexture_getSize(sfSprite_getTexture(button));

    sfRenderWindow_drawSprite(win, button, NULL);
    if (click[0] <= pS.x + (x.x * s_p.x) && click[0] >= pS.x) {
        if (click[1] <= pS.y + (x.y * s_p.y) && click[1] >= pS.y) {
            score[0] = 0;
            score[1] = 0;
            return (1);
        }
    }
    return 0;
}

int end_game(sfRenderWindow *win, sfSprite *back, int *score, sfEvent event)
{
    int quit = 0;
    int play = 0;
    int *click = click_end(win, event);

    sfRenderWindow_drawSprite(win, back, NULL);
    while (sfRenderWindow_isOpen(win) && quit == 0 && play == 0) {
        sfRenderWindow_drawSprite(win, back, NULL);
        text_end(win, score);
        click = click_end(win, event);
        quit = quit_game(win, score, event, click);
        play = replay_game(win, score, event, click);
        sfRenderWindow_display(win);
    }
    return (0);
}

int *click_end(sfRenderWindow *win, sfEvent event)
{
    int *click = malloc(sizeof(int) * 2);
    sfMouseButtonEvent p_c = analyse_events(win, event);

    click[0] = p_c.x * 1400 / sfRenderWindow_getSize(win).x;
    click[1] = p_c.y * 800 / sfRenderWindow_getSize(win).y;
    return (click);
}

int quit_game(sfRenderWindow *win, int *score, sfEvent event, int *click)
{
    sfSprite *button = quit(win);
    sfVector2f pS = sfSprite_getPosition(button);
    sfVector2f s_p = sfSprite_getScale(button);
    sfVector2u x = sfTexture_getSize(sfSprite_getTexture(button));

    sfRenderWindow_drawSprite(win, button, NULL);
    if (click[0] <= pS.x + (x.x * s_p.x) && click[0] >= pS.x) {
        if (click[1] <= pS.y + (x.y * s_p.y) && click[1] >= pS.y) {
            return (1);
        }
    }
    return 0;
}

int det_end(sfSprite *parrot, sfRenderWindow *win, int *b, sfEvent event)
{
    sfVector2f pSprite = sfSprite_getPosition(parrot);

    if (score(parrot, win, event, b) == 1)
        return (1);
    if (pSprite.x >= 1400 && b[0] == 1) {
        b[2] = b[2] + 1;
        return (1);
    }
    if (pSprite.x <= -200 && b[0] == 2) {
        b[2] = b[2] + 1;
        return (1);
    }
    return (0);
}
