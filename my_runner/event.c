/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** manage event
*/

#include "include/my.h"

sfMouseButtonEvent analyse_ev(sfRenderWindow *win, sfEvent even)
{
    sfVector2u size = sfRenderWindow_getSize(win);

    while (sfRenderWindow_pollEvent(win, &even)) {
        if (even.type == sfEvtClosed)
            sfRenderWindow_close(win);
        if (even.type == sfEvtMouseButtonPressed && even.type != sfEvtClosed)
            return (even.mouseButton);
    }
}

int *click_pos(sfRenderWindow *win, sfEvent event)
{
    int *click = malloc(sizeof(int) * 2);
    sfMouseButtonEvent p_c = analyse_ev(win, event);

    click[0] = p_c.x * 800 / sfRenderWindow_getSize(win).x;
    click[1] = p_c.y * 600 / sfRenderWindow_getSize(win).y;
    return (click);
}

int click_ok_play(list *l_a, sfEvent event, sfSprite *sprite, int *click)
{
    sfVector2f pS = sfSprite_getPosition(sprite);
    sfVector2f s_p = sfSprite_getScale(sprite);
    sfVector2u x = sfTexture_getSize(sfSprite_getTexture(sprite));

    if (click[0] <= pS.x + (x.x * s_p.x) && click[0] >= pS.x)
        if (click[1] <= pS.y + (x.y / 2 * s_p.y) && click[1] >= pS.y)
            return (1);
    return 0;
}

int click_ok(list *l_a, sfEvent event, sfSprite *sprite, int *click)
{
    sfVector2f pS = sfSprite_getPosition(sprite);
    sfVector2f s_p = sfSprite_getScale(sprite);
    sfVector2u x = sfTexture_getSize(sfSprite_getTexture(sprite));

    if (click[0] <= pS.x + (x.x * s_p.x) && click[0] >= pS.x)
        if (click[1] <= pS.y + (x.y * s_p.y) && click[1] >= pS.y)
            return (1);
    return 0;
}