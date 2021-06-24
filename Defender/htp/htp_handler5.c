/*
** EPITECH PROJECT, 2021
** defender
** File description:
** htp_handler 5
*/

#include "../include/defender.h"

void event_handler_htp51(game_t *game)
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
        choice_turret(game);
        game->map.turret_menu.clicked = 0;
        display_turret_menu(game);
    }
}

void event_handler_htp5(game_t *game)
{
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
        event_handler_htp51(game);
    }
}

void activate_pause(game_t *game)
{
    game->map.time = game->map.time_base;
    game->map.time += get_time(game);
    sfIntRect my_rect =
    sfSprite_getTextureRect(game->map.freeze.sprite_spell);

    if (game->map.data_htp->started != 1 &&
    game->map.data->points_gold <= 100) {
        game->map.data_htp->started = 1;
        game->map.data_htp->titime = game->map.time;
    }
}

void go_to_pause(game_t *game)
{
    game->map.time = game->map.time_base;
    game->map.time += get_time(game);
    if (game->map.data_htp->started == 1 &&
    game->map.data_htp->titime + 2 < game->map.time) {
        game->handler_scene = &game_display_htp6;
        free(game->map.data_htp->temp);
        free(game->map.data_htp->str);
        read_dialogue(game, "./htp/dialogue_5.txt");
        sfText_setCharacterSize(game->map.data_htp->text, 32);
        load_dark_step2(game, "./asset/bg/dark_pause.png");
        game->map.data_htp->finished = 0;
        game->map.data_htp->current_timer = game->map.time;
        game->map.data_htp->i = 0;
        game->map.data_htp->started = 0;
    }
}

void game_display_htp5(game_t *game)
{
    sfRenderWindow_drawSprite(game->win, game->map.s_background, NULL);
    sfRenderWindow_drawSprite(game->win, game->map.fireball.icone, NULL);
    sfRenderWindow_drawSprite(game->win, game->map.freeze.icone, NULL);
    sfRenderWindow_drawRectangleShape(game->win,
    game->map.pause_button->button, NULL);
    game_display_first_map2(game);
    sfRenderWindow_drawSprite(game->win, game->map.data_htp->dark, NULL);
    handle_hover_turret(game);
    display_turrets(game);
    display_buy_menu(game);
    sfRenderWindow_drawSprite(game->win, game->map.data_htp->bulle, NULL);
    display_typing_0(game);
    sfRenderWindow_drawText(game->win, game->map.data_htp->text, NULL);
    activate_pause(game);
    go_to_pause(game);
    event_handler_htp5(game);
}