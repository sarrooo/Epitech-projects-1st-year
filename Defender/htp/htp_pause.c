/*
** EPITECH PROJECT, 2021
** defender
** File description:
** htp_handler
*/

#include "../include/defender.h"

void handle_pause_htp3(game_t *game)
{
    sfRenderWindow_clear(game->win, sfBlack);
    sfRenderWindow_drawSprite(game->win, game->map.s_background, NULL);
    sfRenderWindow_drawSprite(game->win,
    game->map.fireball.icone, NULL);
}

void handle_pause_htp2(game_t *game)
{
    while (sfRenderWindow_isOpen(game->win) && game->map.paused == 1) {
        handle_pause_htp3(game);
        sfRenderWindow_drawSprite(game->win, game->map.freeze.icone, NULL);
        sfRenderWindow_drawRectangleShape(game->win,
        game->map.pause_button->button, NULL);
        game_display_first_map2(game);
        sfRenderWindow_drawSprite(game->win, game->map.data_htp->dark, NULL);
        sfRenderWindow_drawSprite(game->win, game->map.data_htp->bulle, NULL);
        display_typing_0(game);
        sfRenderWindow_drawText(game->win, game->map.data_htp->text, NULL);
        if (game->map.fireball.animation == 1)
            sfRenderWindow_drawSprite(game->win,
            game->map.fireball.sprite_spell, NULL);
        if (game->map.freeze.animation == 1)
            sfRenderWindow_drawSprite(game->win,
            game->map.freeze.sprite_spell, NULL);
        handler_pause(game, 1);
        sfRenderWindow_display(game->win);
    }
}

void check_sound_htp(game_t *game)
{
    if (game->map.fireball.animation == 1) {
        sfSound_setVolume(game->map.fireball.sound, game->volume);
        sfSound_play(game->map.fireball.sound);
    }
    if (game->map.freeze.animation == 1) {
        sfSound_setVolume(game->map.freeze.sound, game->volume);
        sfSound_play(game->map.freeze.sound);
    }
}

void handle_pause_htp1(game_t *game)
{
    sfClock *my_clock = sfClock_create();

    if (game->map.paused == 1) {
        if (game->map.fireball.animation == 1)
            sfSound_stop(game->map.fireball.sound);
        if (game->map.freeze.animation == 1)
            sfSound_stop(game->map.freeze.sound);
        handle_pause_htp2(game);
        check_sound_htp(game);
        game->map.time_base -=
        sfClock_getElapsedTime(my_clock).microseconds / 1000000.0;
        sfClock_destroy(my_clock);
        game->map.data_htp->started = 1;
        game->map.time = game->map.time_base;
        game->map.time += get_time(game);
        game->map.data_htp->titime = game->map.time;
    }
}