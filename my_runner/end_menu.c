/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** end menu (lose and win)
*/

#include "include/my.h"

void set_button(list *l_a, sfSprite *quit, sfSprite *reload)
{
    sfVector2f pos_q = {425, 300};
    sfVector2f pos_r = {270, 300};
    sfVector2f size_q = {0.7, 0.7};
    sfVector2f size_r = {0.7, 0.7};

    sfSprite_setPosition(quit, pos_q);
    sfSprite_setPosition(reload, pos_r);
    sfSprite_setScale(quit, size_q);
    sfSprite_setScale(reload, size_r);
    sfRenderWindow_drawSprite(l_a->win, quit, NULL);
    sfRenderWindow_drawSprite(l_a->win, reload, NULL);
    text_score_final(l_a->win, l_a);
    text_hight_score_final(l_a->win, l_a);
    text_level_final(l_a->win, l_a);
}

int menu_lose(list *l_a, sfEvent event)
{
    int *click = click_pos(l_a->win, event);
    sfSprite *quit = draw_quit(l_a->win);
    sfSprite *reload = draw_reload(l_a->win);
    l_a->high_score = best_score(l_a);

    while (sfRenderWindow_isOpen(l_a->win)) {
        draw_par(l_a->win, l_a->par);
        sfRenderWindow_drawSprite(l_a->win, l_a->girl->sprite, NULL);
        draw_obs(l_a);
        text_lose(l_a->win);
        set_button(l_a, quit, reload);
        click = click_pos(l_a->win, event);
        if (click_ok(l_a, event, reload, click) == 1)
            return (0);
        if (sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue)
            return (0);
        if (click_ok(l_a, event, quit, click) == 1)
            return (3);
        analyse_ev(l_a->win, event);
        sfRenderWindow_display(l_a->win);
    }
}

int menu_win(list *l_a, sfEvent event)
{
    int *click = click_pos(l_a->win, event);
    sfSprite *quit = draw_quit(l_a->win);
    sfSprite *reload = draw_reload(l_a->win);
    l_a->high_score = best_score(l_a);

    while (sfRenderWindow_isOpen(l_a->win)) {
        draw_par(l_a->win, l_a->par);
        sfRenderWindow_drawSprite(l_a->win, l_a->girl->sprite, NULL);
        draw_obs(l_a);
        text_win(l_a->win);
        set_button(l_a, quit, reload);
        click = click_pos(l_a->win, event);
        if (click_ok(l_a, event, reload, click) == 1)
            return (0);
        if (sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue)
            return (0);
        if (click_ok(l_a, event, quit, click) == 1)
            return (3);
        analyse_ev(l_a->win, event);
        sfRenderWindow_display(l_a->win);
    }
}