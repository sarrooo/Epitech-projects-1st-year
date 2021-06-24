/*
** EPITECH PROJECT, 2021
** defender
** File description:
** pause_map1
*/

#include "../include/defender.h"

void set_pause_on(game_t *game, rect_but boutton)
{
    game->map.paused = 1;
    animation_rect_clic(game, (*game->map.pause_button));
}

void handle_pause3(game_t *game)
{
    sfRenderWindow_clear(game->win, sfBlack);
    sfRenderWindow_drawSprite(game->win, game->map.s_background, NULL);
    sfRenderWindow_drawSprite(game->win,
    game->map.fireball.icone, NULL);
}

void handle_pause2(game_t *game)
{
    while (sfRenderWindow_isOpen(game->win) && game->map.paused == 1) {
        handle_pause3(game);
        sfRenderWindow_drawSprite(game->win, game->map.freeze.icone, NULL);
        sfRenderWindow_drawRectangleShape(game->win,
        game->map.pause_button->button, NULL);
        display_turrets(game);
        display_buy_menu(game);
        if (game->map.fireball.animation == 1)
            sfRenderWindow_drawSprite(game->win,
            game->map.fireball.sprite_spell, NULL);
        if (game->map.freeze.animation == 1)
            sfRenderWindow_drawSprite(game->win,
            game->map.freeze.sprite_spell, NULL);
        for (int i = 0; i < game->map.monster_wave->nb_monster; i++)
            if (game->map.monster_wave->monster[i].if_dead == 0)
                draw_monster(game, i);
        handler_pause(game, 0);
        sfRenderWindow_display(game->win);
        }
}

void handle_pause(game_t *game)
{
    if (game->map.paused == 1) {
        sfClock *my_clock = sfClock_create();
        if (game->map.fireball.animation == 1)
            sfSound_stop(game->map.fireball.sound);
        if (game->map.freeze.animation == 1)
            sfSound_stop(game->map.freeze.sound);
        handle_pause2(game);
        if (game->map.fireball.animation == 1)
            sfSound_play(game->map.fireball.sound);
        if (game->map.freeze.animation == 1)
            sfSound_play(game->map.freeze.sound);
        game->map.time_base -=
        sfClock_getElapsedTime(my_clock).microseconds / 1000000.0;
        sfClock_destroy(my_clock);
    }
}