/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** manage jump move
*/

#include "include/my.h"

int jump(list *l_a, sfEvent event)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds;
    sfIntRect *rect = rect_jump(1250, 1250);
    sfVector2f offset = {0, -80};

    sfMusic_play(l_a->jump_fx);
    sfMusic_play(l_a->jump_fx);
    sfSprite_move(l_a->girl->sprite, offset);
    while (1) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (jump_move(l_a, rect) != 0)
            return (1);
        analyse_ev(l_a->win, event);
        if (seconds > 0.8)
            break;
    }
    end_jump(l_a);
    sfClock_destroy(clock);
}

void jump_sprite(sfRenderWindow *win, object *girl, sfIntRect *rect)
{
    sfVector2f s;

    rect->left = rect->left + 1250;
    rect->width = rect->width;
    rect->height = rect->height;
    s.x = 0.09;
    s.y = 0.09;
    if (rect->left >= 5000)
        rect->left = rect->left - 1250;
    sfSprite_setTextureRect(girl->sprite, *rect);
    sfRenderWindow_drawSprite(win, girl->sprite, NULL);
}

void display_end(list *l_a)
{
    text_score(l_a->win, l_a);
    text_high_score(l_a->win, l_a);
    text_level(l_a->win, l_a);
    l_a->score = l_a->score + 0.5;
    l_a->level = l_a->level + 1;
    sfRenderWindow_drawSprite(l_a->win, l_a->girl->sprite, NULL);
    sfRenderWindow_drawSprite(l_a->win, l_a->pause->sprite, NULL);
    sfRenderWindow_drawSprite(l_a->win, l_a->music_but->sprite, NULL);
}

int end_jump(list *l_a)
{
    sfVector2f offset_2 = {0, 20};

    for (int i = 0; i < 4; i++) {
        draw_par(l_a->win, l_a->par);
        sfSprite_move(l_a->girl->sprite, offset_2);
        move_obs(l_a);
        display_end(l_a);
        draw_obs(l_a);
        if (girl_hitbox(l_a) == 1)
            return (2);
        if (check_end_line(l_a) == 1)
            return (1);
        sfRenderWindow_display(l_a->win);
        move_all_par(l_a->win, l_a->par);
        count_seconds(l_a->win);
    }
}

int jump_move(list *l_a, sfIntRect *rect)
{
    draw_par(l_a->win, l_a->par);
    move_obs(l_a);
    sfRenderWindow_drawSprite(l_a->win, l_a->pause->sprite, NULL);
    sfRenderWindow_drawSprite(l_a->win, l_a->music_but->sprite, NULL);
    jump_sprite(l_a->win, l_a->girl, rect);
    draw_obs(l_a);
    text_score(l_a->win, l_a);
    text_high_score(l_a->win, l_a);
    text_level(l_a->win, l_a);
    l_a->score = l_a->score + 0.5;
    l_a->level = l_a->level + 1;
    if (girl_hitbox(l_a) == 1)
        return (2);
    if (check_end_line(l_a) == 1)
        return (1);
    sfRenderWindow_display(l_a->win);
    move_all_par(l_a->win, l_a->par);
    count_seconds(l_a->win);
}