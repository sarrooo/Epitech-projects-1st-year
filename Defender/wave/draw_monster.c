/*
** EPITECH PROJECT, 2021
** defender
** File description:
** draw monster
*/

#include "../include/defender.h"

void draw_monster2(game_t *main_s, int i)
{
    main_s->map.time = main_s->map.time_base;
    main_s->map.time += get_time(main_s);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->map.monster_wave->monster[i].sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->map.monster_wave->monster[i].bar_bg->sprite, NULL);
    sfRenderWindow_drawSprite(main_s->win,
    main_s->map.monster_wave->monster[i].bar->sprite, NULL);
}

void draw_monster(game_t *main_s, int i)
{
    sfVector2f pos_mob =
    sfSprite_getPosition(main_s->map.monster_wave->monster[i].sprite);
    int elec = main_s->map.monster_wave->monster[i].electrise;
    sfVector2u sizetex
    = sfTexture_getSize(main_s->map.monster_wave->monster[i].texture);

    draw_monster2(main_s, i);
    if (elec > 0 && main_s->map.towers[elec - 1].type != 0
    && main_s->map.towers[elec - 1].timer + 0.5 >
    main_s->map.time) {
        sfSprite_setPosition(main_s->map.towers[elec - 1].thunder,
        (sfVector2f){pos_mob.x + sizetex.x / 200, pos_mob.y});
        sfSprite_setColor(main_s->map.monster_wave->monster[i].sprite,
        sfGreen);
        sfRenderWindow_drawSprite(main_s->win,
        main_s->map.monster_wave->monster[i].sprite, NULL);
        sfRenderWindow_drawSprite(main_s->win,
        main_s->map.towers[elec - 1].thunder, NULL);
    }
}