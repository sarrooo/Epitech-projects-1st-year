/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init rect button for settings
*/

#include "include/defender.h"

void setting_rect_button(game_t *main_s)
{
    sfVector2u size_win = sfRenderWindow_getSize(main_s->win);
    info_t info;

    info.callback = on_off_music;
    info.size = int_to_sfvector2f(131, 63);
    if (sfMusic_getStatus(main_s->music) == sfPlaying)
        info.path = "asset/button/button_on.png";
    else
        info.path = "asset/button/button_off.png";
    info.pos.x = ((size_win.x / 2) - 65) - 130;
    info.pos.y = ((size_win.y / 2) - 31) - 50;
    rect_button(main_s, info, main_s->menu_setting->on_off_button);
    info.callback = on_off_sound;
    info.size = int_to_sfvector2f(131, 63);
    if (sfMusic_getStatus(main_s->music) == sfPlaying)
        info.path = "asset/button/button_on.png";
    else
        info.path = "asset/button/button_off.png";
    info.pos.x = ((size_win.x / 2) - 65) - 130;
    info.pos.y = ((size_win.y / 2) - 31) + 100;
    rect_button(main_s, info, main_s->menu_setting->on_off_button_2);
}