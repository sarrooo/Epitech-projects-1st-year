/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** function for on off music button menu
*/

#include "include/defender.h"

void update_music_button_menu(game_t *main_s)
{
    int idx = main_s->current_scene;
    sfTexture *texture;

    if (sfMusic_getStatus(main_s->music) == sfPlaying) {
        texture = sfTexture_createFromFile("asset/button/music_on.png", NULL);
        sfTexture_destroy(main_s->menu_scene->music_but->texture);
        sfRectangleShape_setTexture(main_s->menu_scene->music_but->button,
        texture, sfTrue);
        main_s->menu_scene->music_but->texture = texture;
    }
    else {
        texture = sfTexture_createFromFile("asset/button/music_off.png", NULL);
        sfTexture_destroy(main_s->menu_scene->music_but->texture);
        sfRectangleShape_setTexture(main_s->menu_scene->music_but->button,
        texture, sfTrue);
        main_s->menu_scene->music_but->texture = texture;
    }
}

void play_stop_music(game_t *main_s)
{
    int idx = main_s->current_scene;
    sfTexture *texture;

    animation_rect_clic(main_s, *main_s->menu_scene->music_but);
    if (sfMusic_getStatus(main_s->music) == sfPlaying) {
        texture = sfTexture_createFromFile("asset/button/music_off.png", NULL);
        sfTexture_destroy(main_s->menu_scene->music_but->texture);
        sfRectangleShape_setTexture(main_s->menu_scene->music_but->button,
        texture, sfTrue);
        main_s->menu_scene->music_but->texture = texture;
        sfMusic_pause(main_s->music);
    }
    else {
        texture = sfTexture_createFromFile("asset/button/music_on.png", NULL);
        sfTexture_destroy(main_s->menu_scene->music_but->texture);
        sfRectangleShape_setTexture(main_s->menu_scene->music_but->button,
        texture, sfTrue);
        main_s->menu_scene->music_but->texture = texture;
        sfMusic_play(main_s->music);
    }
}