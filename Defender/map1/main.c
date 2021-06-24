/*
** EPITECH PROJECT, 2021
** map1
** File description:
** handler
*/

#include "../include/defender.h"

void handle_event_first_map2(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed) {
        if (choose_action(game) == 1) {
            game->map.turret_menu.sell_clicked = 0;
            return;
        }
        game->map.turret_menu.sell_clicked = 0;
        display_sell_menu(game);
        choice_turret(game);
        game->map.turret_menu.clicked = 0;
        display_turret_menu(game);
        handle_targeting(game);
        rect_clic_call(game, game->map.pause_button, game->mouse_pos);
    } else {
        animation_rect_none(game, game->map.pause_button);
        sfSprite_setScale(game->map.fireball.icone, (sfVector2f){1, 1});
        sfSprite_setScale(game->map.freeze.icone, (sfVector2f){1, 1});
        sfSprite_setPosition(game->map.fireball.icone, (sfVector2f){0, 0});
        sfSprite_setPosition(game->map.freeze.icone, (sfVector2f){0, 100});
    }
}

void handle_event_first_map(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->win, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->win);
            break;
        }
        if (game->event.type == sfEvtMouseMoved) {
            handle_move(game, game->event.mouseMove);
        }
        handle_event_first_map2(game);
        if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeyEscape)
            game->map.paused *= -1;
    }
}

void game_display_first_map2(game_t *game)
{
    set_text(game);
    sfRenderWindow_drawSprite(game->win, game->map.data->s_gold, NULL);
    sfRenderWindow_drawSprite(game->win, game->map.data->s_wave, NULL);
    sfRenderWindow_drawText(game->win, game->map.data->wave, NULL);
    sfRenderWindow_drawText(game->win, game->map.data->gold, NULL);
    sfRenderWindow_drawText(game->win, game->map.data->life, NULL);
}

void game_display_first_map(game_t *game)
{
    sfRenderWindow_drawSprite(game->win, game->map.s_background, NULL);
    sfRenderWindow_drawSprite(game->win, game->map.fireball.icone, NULL);
    sfRenderWindow_drawSprite(game->win, game->map.freeze.icone, NULL);
    sfRenderWindow_drawRectangleShape(game->win,
    game->map.pause_button->button, NULL);
    is_rect_hover(game, game->map.pause_button->button, game->mouse_pos);
    game_display_first_map2(game);
    handler_wave(game);
    handler_arrow(game);
    display_turrets(game);
    handle_hover_turret(game);
    handle_hover_spell(game);
    spell_cursor(game);
    animation_spell_fire(game);
    animation_spell_freeze(game);
    display_buy_menu(game);
    display_menu_sell(game);
    handle_event_first_map(game);
    handle_pause(game);
}