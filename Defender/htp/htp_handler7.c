/*
** EPITECH PROJECT, 2021
** defender
** File description:
** htp handler 7
*/

#include "../include/defender.h"

void event_handler_htp71(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed &&
    game->event.key.code == sfKeyEnter) {
        if (game->map.data_htp->finished == 1) {
            game->current_scene = MENU;
            game->scene_config = &init_menu_scenes;
        }
        if (game->map.data_htp->finished != 1) {
            my_strcpy(game->map.data_htp->temp, game->map.data_htp->str);
            sfText_setString(game->map.data_htp->text,
            game->map.data_htp->temp);
            game->map.data_htp->finished = 1;
            sfSound_stop(game->map.data_htp->tping);
        }
    }
}

void event_handler_htp7(game_t *game)
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
        event_handler_htp71(game);
    }
}

void game_display_htp7(game_t *game)
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
    event_handler_htp7(game);
}