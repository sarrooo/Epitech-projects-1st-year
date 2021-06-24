/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** event for pause menu
*/

#include "../include/defender.h"

void check_pause_event2(game_t *main_s, sfEvent et, int on)
{
    if (et.type == sfEvtClosed)
        sfRenderWindow_close(main_s->win);
    if (et.type == sfEvtKeyPressed && et.key.code == sfKeyEscape)
        main_s->map.paused *= -1;
    if (on == 1) {
        main_s->map.data_htp->started = 1;
    }
}

void check_pause_event(game_t *main_s, int on)
{
    sfEvent et = main_s->event;
    const sfView *view = sfRenderWindow_getView(main_s->win);
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(main_s->win);
    sfVector2f pos_mouse;

    pos_mouse = sfRenderWindow_mapPixelToCoords(main_s->win, p_mouse, view);
    while (sfRenderWindow_pollEvent(main_s->win, &et)) {
        check_pause_event2(main_s, et, on);
        check_pause_hover(main_s, pos_mouse);
        if (et.type == sfEvtMouseButtonPressed && et.type != sfEvtClosed) {
            p_mouse.x = et.mouseButton.x;
            p_mouse.y = et.mouseButton.y;
            pos_mouse = sfRenderWindow_mapPixelToCoords(main_s->win,
            p_mouse, view);
            check_pause_clic(main_s, pos_mouse);
        }
        else
            pause_check_button_none(main_s);
    }
}