/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** function for sound button main menu
*/

#include "include/defender.h"

void update_sound_button_menu(game_t *main_s)
{
    int idx = main_s->current_scene;
    sfTexture *texture;

    if (main_s->volume == 0.0) {
        texture = sfTexture_createFromFile("asset/button/sound_off.png", NULL);
        sfTexture_destroy(main_s->menu_scene->sound_but->texture);
        sfRectangleShape_setTexture(main_s->menu_scene->sound_but->button,
        texture, sfTrue);
        main_s->menu_scene->sound_but->texture = texture;
    }
    else {
        texture = sfTexture_createFromFile("asset/button/sound_on.png", NULL);
        sfTexture_destroy(main_s->menu_scene->sound_but->texture);
        sfRectangleShape_setTexture(main_s->menu_scene->sound_but->button,
        texture, sfTrue);
        main_s->menu_scene->sound_but->texture = texture;
    }
}

void play_stop_fx(game_t *main_s)
{
    int idx = main_s->current_scene;
    sfTexture *texture;

    animation_rect_clic(main_s, *main_s->menu_scene->sound_but);
    if (main_s->volume == 0.0) {
        texture = sfTexture_createFromFile("asset/button/sound_on.png", NULL);
        sfTexture_destroy(main_s->menu_scene->sound_but->texture);
        sfRectangleShape_setTexture(main_s->menu_scene->sound_but->button,
        texture, sfTrue);
        main_s->menu_scene->sound_but->texture = texture;
        main_s->volume = 100.0;
    }
    else {
        texture = sfTexture_createFromFile("asset/button/sound_off.png", NULL);
        sfTexture_destroy(main_s->menu_scene->sound_but->texture);
        sfRectangleShape_setTexture(main_s->menu_scene->sound_but->button,
        texture, sfTrue);
        main_s->menu_scene->sound_but->texture = texture;
        main_s->volume = 0.0;
    }
}