/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init health bar
*/

#include "include/defender.h"

void refresh_health_bar(monster_t *monster, int index)
{
    sfVector2f pos = sfSprite_getPosition(monster[index].sprite);
    int health = monster[index].health;
    int health_orignal = monster[index].health_original;
    sfVector2f scale = sfSprite_getScale(monster[index].sprite);
    sfVector2f scale_bar = sfSprite_getScale(monster[index].bar_bg->sprite);
    sfIntRect rect;

    pos.y -= monster[index].offset_bar;
    pos.x = pos.x + (monster[index].rect.width * scale.x / 2);
    pos.x = pos.x - ((708 * scale_bar.x) / 2);
    sfSprite_setPosition(monster[index].bar_bg->sprite, pos);
    sfSprite_setPosition(monster[index].bar->sprite, pos);
    rect.height = 80;
    rect.width= health * 709 / health_orignal;
    rect.top = 0;
    rect.left = 0;
    sfSprite_setTextureRect(monster[index].bar->sprite, rect);
}

void init_bar_healt(game_t *main_s, monster_t *monster, monster_info info_1)
{
    info_t info;
    int index = info_1.index;

    monster[index].bar_bg = malloc(sizeof(object_t));
    monster[index].bar = malloc(sizeof(object_t));
    info.pos = info_1.spaw_point;
    info.pos.y -= monster[index].offset_bar;
    info.pos.x = (monster[index].rect.width / 2) - ((708 * 0.09) / 2);
    info.scale = info_1.scale;
    info.path = "asset/character/health_bar_bg.png";
    init_object(main_s, info, monster[index].bar_bg);
    info.path = "asset/character/health_bar.png";
    init_object(main_s, info, monster[index].bar);
}
