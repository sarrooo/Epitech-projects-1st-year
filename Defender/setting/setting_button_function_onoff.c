/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** function for button on off setting
*/

#include "include/defender.h"

void update_button_music_setting(game_t *main_s)
{
    sfTexture *text;
    sfRectangleShape *button = main_s->menu_setting->on_off_button->button;

    if (sfMusic_getStatus(main_s->music) == sfPaused) {
        text = sfTexture_createFromFile("asset/button/button_off.png", NULL);
        sfTexture_destroy(main_s->menu_setting->on_off_button->texture);
        sfRectangleShape_setTexture(button, text, sfTrue);
        main_s->menu_setting->on_off_button->texture = text;
    }
    else {
        text = sfTexture_createFromFile("asset/button/button_on.png", NULL);
        sfTexture_destroy(main_s->menu_setting->on_off_button->texture);
        sfRectangleShape_setTexture(button, text, sfTrue);
        main_s->menu_setting->on_off_button->texture = text;
    }
}

void on_off_music(game_t *main_s)
{
    sfTexture *text;
    sfRectangleShape *button = main_s->menu_setting->on_off_button->button;

    animation_rect_clic(main_s, *main_s->menu_setting->on_off_button);
    if (sfMusic_getStatus(main_s->music) == sfPlaying) {
        text = sfTexture_createFromFile("asset/button/button_off.png", NULL);
        sfTexture_destroy(main_s->menu_setting->on_off_button->texture);
        sfRectangleShape_setTexture(button, text, sfTrue);
        main_s->menu_setting->on_off_button->texture = text;
        sfMusic_pause(main_s->music);
    }
    else {
        text = sfTexture_createFromFile("asset/button/button_on.png", NULL);
        sfTexture_destroy(main_s->menu_setting->on_off_button->texture);
        sfRectangleShape_setTexture(button, text, sfTrue);
        main_s->menu_setting->on_off_button->texture = text;
        sfMusic_play(main_s->music);
    }
}

void update_button_sound_setting(game_t *main_s)
{
    sfTexture *text;
    sfRectangleShape *button = main_s->menu_setting->on_off_button_2->button;

    if (main_s->volume == 0.0) {
        text = sfTexture_createFromFile("asset/button/button_off.png", NULL);
        sfTexture_destroy(main_s->menu_setting->on_off_button_2->texture);
        sfRectangleShape_setTexture(button, text, sfTrue);
        main_s->menu_setting->on_off_button_2->texture = text;
    }
    else {
        text = sfTexture_createFromFile("asset/button/button_on.png", NULL);
        sfTexture_destroy(main_s->menu_setting->on_off_button_2->texture);
        sfRectangleShape_setTexture(button, text, sfTrue);
        main_s->menu_setting->on_off_button_2->texture = text;
    }
}

void on_off_sound(game_t *main_s)
{
    sfTexture *text;
    sfRectangleShape *button = main_s->menu_setting->on_off_button_2->button;

    animation_rect_clic(main_s, *main_s->menu_setting->on_off_button_2);
    if (main_s->volume == 0.0) {
        text = sfTexture_createFromFile("asset/button/button_on.png", NULL);
        sfTexture_destroy(main_s->menu_setting->on_off_button_2->texture);
        sfRectangleShape_setTexture(button, text, sfTrue);
        main_s->menu_setting->on_off_button_2->texture = text;
        main_s->volume = 100.0;
    }
    else {
        text = sfTexture_createFromFile("asset/button/button_off.png", NULL);
        sfTexture_destroy(main_s->menu_setting->on_off_button_2->texture);
        sfRectangleShape_setTexture(button, text, sfTrue);
        main_s->menu_setting->on_off_button_2->texture = text;
        main_s->volume = 0.0;
    }
}