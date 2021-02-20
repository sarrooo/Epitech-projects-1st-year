/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** main
*/

#include "include/my.h"

int main_loop(list *l_a, sfEvent event)
{
    draw_par(l_a->win, l_a->par);
    text_score(l_a->win, l_a);
    text_high_score(l_a->win, l_a);
    text_level(l_a->win, l_a);
    move_girl(l_a->win, l_a->girl, l_a->girl->rect, l_a);
    sfRenderWindow_drawSprite(l_a->win, l_a->pause->sprite, NULL);
    sfRenderWindow_drawSprite(l_a->win, l_a->music_but->sprite, NULL);
    if (check_end_line(l_a) == 1)
        return (1);
    move_obs(l_a);
    draw_obs(l_a);
    sfRenderWindow_display(l_a->win);
    move_all_par(l_a->win, l_a->par);
    count_seconds(l_a->win);
    manage_move(l_a, event);
    l_a->score = l_a->score + 0.5;
    l_a->level = l_a->level + 1;
    return (0);
}

int start_main(list *l_a)
{
    sfVector2f pos = {670, 10};
    sfVector2f pos_end = l_a->list_enemy->end->pos;

    struct_obs(l_a);
    set_pos_obs(l_a);
    sfSprite_setPosition(l_a->list_enemy->end->sprite, pos_end);
    l_a->girl = create_girl(l_a->win);
    l_a->pause->sprite = draw_pause(l_a->win);
    l_a->girl->rect = rect_sprite(1250, 1250);
    sfSprite_setPosition(l_a->music_but->sprite, pos);
    reset_paralax(l_a);
    l_a->score = 0;
    l_a->level = 0;
}

int main_game(list *l_a, sfEvent event)
{
    int *click = click_pos(l_a->win, event);
    int end = 0;

    start_main(l_a);
    while (sfRenderWindow_isOpen(l_a->win)) {
        if (main_loop(l_a, event) == 1)
            return (1);
        if (girl_hitbox(l_a) == 1)
            return (2);
        click = click_pos(l_a->win, event);
        if (click_ok(l_a, event, l_a->music_but->sprite, click) == 1)
            manage_click_music(l_a, event, l_a->music_but->sprite);
        if (click_ok(l_a, event, l_a->pause->sprite, click) == 1)
            end = menu_pause(l_a, event);
        if (end == 1)
            return (2);
    }
    return (0);
}

int main(int ac, char **av)
{
    paralax *par = create_par();
    sfRenderWindow *win = create_window(win, par->b_6);
    list *l_a = make_struct(win, par, back_sound());
    int end = 0;
    sfEvent event;

    if (error(l_a, ac, av) == 84)
        return EXIT_FAILURE;
    struct_obs(l_a);
    launch_menu(l_a, event);
    best_score(l_a);
    while (sfRenderWindow_isOpen(win) && end == 0) {
        end = main_game(l_a, event);
        if (end == 2)
            end = menu_lose(l_a, event);
        if (end == 1)
            end = menu_win(l_a, event);
    }
    destroy_all(l_a);
    return EXIT_SUCCESS;
}