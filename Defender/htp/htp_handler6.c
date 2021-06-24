/*
** EPITECH PROJECT, 2021
** defender
** File description:
** htp handler 6
*/

#include "../include/defender.h"

void event_handler_htp61(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed &&
    game->event.key.code == sfKeyEnter) {
        if (game->map.data_htp->finished != 1) {
            my_strcpy(game->map.data_htp->temp, game->map.data_htp->str);
            sfText_setString(game->map.data_htp->text,
            game->map.data_htp->temp);
            game->map.data_htp->finished = 1;
            sfSound_stop(game->map.data_htp->tping);
        }
    }
    if (game->event.type == sfEvtMouseButtonPressed) {
        rect_clic_call(game, game->map.pause_button, game->mouse_pos);
    }
}

void event_handler_htp6(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->win, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->win);
            break;
        }
        if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeyEscape) {
            game->map.paused *= -1;
        }
        if (game->event.type == sfEvtMouseMoved) {
            handle_move(game, game->event.mouseMove);
        }
        event_handler_htp61(game);
    }
}

void finish(game_t *game)
{
    game->map.time = game->map.time_base;
    game->map.time += get_time(game);
    if (game->map.data_htp->started == 1 &&
    game->map.data_htp->titime + 2 < game->map.time) {
        game->handler_scene = &game_display_htp7;
        free(game->map.data_htp->temp);
        free(game->map.data_htp->str);
        read_dialogue(game, "./htp/dialogue_6.txt");
        sfText_setCharacterSize(game->map.data_htp->text, 32);
        load_dark_step2(game, "./asset/bg/dark.png");
        game->map.data_htp->finished = 0;
        game->map.data_htp->current_timer = game->map.time;
        game->map.data_htp->i = 0;
        game->map.data_htp->started = 0;
    }
}

void game_display_htp6(game_t *game)
{
    sfRenderWindow_drawSprite(game->win, game->map.s_background, NULL);
    sfRenderWindow_drawSprite(game->win, game->map.fireball.icone, NULL);
    sfRenderWindow_drawSprite(game->win, game->map.freeze.icone, NULL);
    sfRenderWindow_drawRectangleShape(game->win,
    game->map.pause_button->button, NULL);
    is_rect_hover(game, game->map.pause_button->button, game->mouse_pos);
    game_display_first_map2(game);
    sfRenderWindow_drawSprite(game->win, game->map.data_htp->dark, NULL);
    sfRenderWindow_drawSprite(game->win, game->map.data_htp->bulle, NULL);
    display_typing_0(game);
    sfRenderWindow_drawText(game->win, game->map.data_htp->text, NULL);
    event_handler_htp6(game);
    finish(game);
    handle_pause_htp1(game);
}