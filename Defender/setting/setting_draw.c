/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** draw all for settings
*/

#include "include/defender.h"

void draw_rect_setting(game_t *main_s)
{
    sfRenderWindow_drawRectangleShape(main_s->win,
    main_s->menu_setting->on_off_button->button, NULL);
    sfRenderWindow_drawRectangleShape(main_s->win,
    main_s->menu_setting->on_off_button_2->button, NULL);
}

void draw_circle_setting(game_t *main_s)
{
    sfRenderWindow_drawCircleShape(main_s->win,
    main_s->menu_setting->quit_but->button, NULL);
    sfRenderWindow_drawCircleShape(main_s->win,
    main_s->menu_setting->music_minus->button, NULL);
    sfRenderWindow_drawCircleShape(main_s->win,
    main_s->menu_setting->music_plus->button, NULL);
    sfRenderWindow_drawCircleShape(main_s->win,
    main_s->menu_setting->rate_minus->button, NULL);
    sfRenderWindow_drawCircleShape(main_s->win,
    main_s->menu_setting->rate_plus->button, NULL);
}

void draw_object_setting(game_t *main_s)
{
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_setting->background->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_setting->dark->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_setting->plank->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_setting->rope_1->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_setting->rope_2->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_setting->header->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_setting->music_bar_bg->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_setting->rate_bar_bg->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_setting->music_bar->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->menu_setting->rate_bar->sprite, NULL);
}

void draw_text_setting(game_t *main_s)
{
    sfRenderWindow_drawText(main_s->win,
    main_s->menu_setting->music_txt->text, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->menu_setting->sound_txt->text, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->menu_setting->music_volume->text, NULL);
    sfRenderWindow_drawText(main_s->win,
    main_s->menu_setting->graphic->text, NULL);
}

void draw_setting(game_t *main_s)
{
    draw_object_setting(main_s);
    draw_rect_setting(main_s);
    draw_circle_setting(main_s);
    draw_text_setting(main_s);
}