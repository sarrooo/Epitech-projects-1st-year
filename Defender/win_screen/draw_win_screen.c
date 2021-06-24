/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** draw all object for win screen
*/

#include "include/defender.h"

void draw_win_screen_object(game_t *main_s)
{
    sfRenderWindow_drawSprite(main_s->win,
    main_s->win_screen->background->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->win_screen->dark->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->win_screen->plank->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->win_screen->header->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->win_screen->bg_star->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->win_screen->star->sprite, NULL);
}

void draw_scoreboard_win_screen(game_t *main_s)
{
    sfRenderWindow_drawSprite(main_s->win,
    main_s->win_screen->plank_scoreboard->sprite, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->win_screen->header_scoreboard->text, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->win_screen->first_place->text, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->win_screen->second_place->text, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->win_screen->third_place->text, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->win_screen->fourth_place->text, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->win_screen->fifth_place->text, NULL);
}

void draw_win_screen(game_t *main_s)
{
    draw_win_screen_object(main_s);
    sfRenderWindow_drawRectangleShape(main_s->win,
    main_s->win_screen->menu_button->button, NULL);
    sfRenderWindow_drawRectangleShape(main_s->win,
    main_s->win_screen->replay_button->button, NULL);
    sfRenderWindow_drawCircleShape(main_s->win,
    main_s->win_screen->quit_button->button, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->win_screen->message_1->text, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->win_screen->message_2->text, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->win_screen->score_txt->text, NULL);
    draw_scoreboard_win_screen(main_s);
}