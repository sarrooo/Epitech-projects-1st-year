/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** darw object for scoreboard
*/

#include "include/defender.h"

void draw_scoreboard(game_t *main_s)
{
    sfRenderWindow_drawSprite(main_s->win,
    main_s->scoreboard->background->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->scoreboard->dark->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->scoreboard->plank->sprite, NULL);
    sfRenderWindow_drawCircleShape(main_s->win,
    main_s->scoreboard->quit_button->button, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->scoreboard->header->text, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->scoreboard->first_place->text, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->scoreboard->second_place->text, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->scoreboard->third_place->text, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->scoreboard->fourth_place->text, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->scoreboard->fifth_place->text, NULL);
}