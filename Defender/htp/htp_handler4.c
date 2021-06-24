/*
** EPITECH PROJECT, 2021
** defender
** File description:
** htp handler 4
*/

#include "../include/defender.h"

void event_handler_htp41(game_t *game)
{
    if (game->map.data_htp->finished == 1) {
        game->handler_scene = &game_display_htp5;
        free(game->map.data_htp->temp);
        free(game->map.data_htp->str);
        read_dialogue(game, "./htp/dialogue_4.txt");
        load_dark_step2(game, "./asset/bg/dark_turret.png");
        game->map.data_htp->finished = 0;
        sfText_setCharacterSize(game->map.data_htp->text, 35);
        game->map.data_htp->current_timer = game->map.time;
        game->map.data_htp->i = 0;
        return;
    }
    if (game->map.data_htp->finished != 1) {
        my_strcpy(game->map.data_htp->temp, game->map.data_htp->str);
        sfText_setString(game->map.data_htp->text,
        game->map.data_htp->temp);
        game->map.data_htp->finished = 1;
        sfSound_stop(game->map.data_htp->tping);
    }
}

void event_handler_htp4(game_t *game)
{
    game->map.time = game->map.time_base;
    game->map.time += get_time(game);
    while (sfRenderWindow_pollEvent(game->win, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->win);
            break;
        }
        if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeyEscape) {
            game->current_scene = MENU;
            game->scene_config = &init_menu_scenes;
        }
        if (game->event.type == sfEvtMouseMoved) {
            handle_move(game, game->event.mouseMove);
        }
        if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeyEnter) {
            event_handler_htp41(game);
        }
    }
}

void game_display_htp4(game_t *game)
{
    sfRenderWindow_drawSprite(game->win, game->map.s_background, NULL);
    sfRenderWindow_drawSprite(game->win, game->map.fireball.icone, NULL);
    sfRenderWindow_drawSprite(game->win, game->map.freeze.icone, NULL);
    sfRenderWindow_drawRectangleShape(game->win,
    game->map.pause_button->button, NULL);
    game_display_first_map2(game);
    sfRenderWindow_drawSprite(game->win, game->map.data_htp->dark, NULL);
    sfRenderWindow_drawSprite(game->win, game->map.data_htp->bulle, NULL);
    display_typing_0(game);
    sfRenderWindow_drawText(game->win, game->map.data_htp->text, NULL);
    event_handler_htp4(game);
}