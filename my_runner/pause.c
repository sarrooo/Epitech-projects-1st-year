/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** pause menu
*/

#include "include/my.h"

void draw_sprite_pause(list *l_a, sfSprite *quit, sfSprite *rel, sfSprite *res)
{
    draw_par(l_a->win, l_a->par);
    sfRenderWindow_drawSprite(l_a->win, l_a->girl->sprite, NULL);
    sfRenderWindow_drawSprite(l_a->win, quit, NULL);
    sfRenderWindow_drawSprite(l_a->win, rel, NULL);
    sfRenderWindow_drawSprite(l_a->win, res, NULL);
    sfRenderWindow_drawSprite(l_a->win, l_a->music_but->sprite, NULL);
    text_score(l_a->win, l_a);
    text_high_score(l_a->win, l_a);
    text_level(l_a->win, l_a);
    draw_obs(l_a);
    text_pause(l_a->win);
}

int menu_pause(list *l_a, sfEvent event)
{
    int *click = click_pos(l_a->win, event);
    sfSprite *quit = draw_quit(l_a->win);
    sfSprite *reload = draw_reload(l_a->win);
    sfSprite *resume = draw_resume(l_a->win);
    sfVector2f pos = {10, 10};

    while (sfRenderWindow_isOpen(l_a->win)) {
        click = click_pos(l_a->win, event);
        draw_sprite_pause(l_a, quit, reload, resume);
        if (click_ok(l_a, event, l_a->music_but->sprite, click) == 1)
            manage_click_music(l_a, event, l_a->music_but->sprite);
        if (click_ok(l_a, event, resume, click) == 1)
            return (0);
        if (click_ok(l_a, event, reload, click) == 1) {
            main_game(l_a, event);
            return (1);
        }
        if (click_ok(l_a, event, quit, click) == 1)
            sfRenderWindow_close(l_a->win);
        sfRenderWindow_display(l_a->win);
    }
}