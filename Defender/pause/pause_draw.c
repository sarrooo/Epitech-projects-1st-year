/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** draw all for pause menu
*/

#include "include/defender.h"

void draw_object_pause(game_t *main_s)
{
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_pause->dark->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_pause->plank->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_pause->rope_1->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_pause->rope_2->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_pause->music_bar_bg->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_pause->rate_bar_bg->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_pause->music_bar->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_pause->rate_bar->sprite, NULL);
}

void draw_text_pause(game_t *main_s)
{
    sfRenderWindow_drawText(main_s->win,
    main_s->menu_pause->header->text, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->menu_pause->music_volume->text, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->menu_pause->sound_volume->text, NULL);
}

void draw_circle_pause(game_t *main_s)
{
    sfRenderWindow_drawCircleShape(main_s->win,
    main_s->menu_pause->music_plus->button, NULL);
    sfRenderWindow_drawCircleShape(main_s->win,
    main_s->menu_pause->music_minus->button, NULL);
    sfRenderWindow_drawCircleShape(main_s->win,
    main_s->menu_pause->rate_plus->button, NULL);
    sfRenderWindow_drawCircleShape(main_s->win,
    main_s->menu_pause->rate_minus->button, NULL);
    sfRenderWindow_drawCircleShape(main_s->win,
    main_s->menu_pause->resume->button, NULL);
}

void draw_rect_pause(game_t *main_s)
{
    sfRenderWindow_drawRectangleShape(main_s->win,
    main_s->menu_pause->menu->button, NULL);
    sfRenderWindow_drawRectangleShape(main_s->win,
    main_s->menu_pause->quit->button, NULL);
}

void draw_pause(game_t *main_s)
{
    draw_object_pause(main_s);
    draw_circle_pause(main_s);
    draw_text_pause(main_s);
    draw_rect_pause(main_s);
}