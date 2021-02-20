/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** hitbox
*/

#include "include/my.h"

float *cut_image(obs *element)
{
    float *cut = malloc(sizeof(int) * 2);

    if (element->type == 1) {
        cut[0] = 3;
        cut[1] = 6;
    }
    if (element->type == 2) {
        cut[0] = 4;
        cut[1] = 3;
    }
    if (element->type == 3) {
        cut[0] = 3;
        cut[1] = 4;
    }
    if (element->type == 4 || element->type == 5) {
        cut[0] = 1;
        cut[1] = 1.2;
    }
    return (cut);
}

unsigned int *hitbox_obs(obs *element)
{
    unsigned int x_1;
    unsigned int y_1;
    unsigned int x_obs;
    unsigned int y_obs;
    float *cut = cut_image(element);
    unsigned int *size_obs = malloc(sizeof(unsigned int) * 2);

    x_1 = sfTexture_getSize(element->texture).x / cut[0];
    y_1 = sfTexture_getSize(element->texture).y / cut[1];
    x_obs = x_1 * sfSprite_getScale(element->sprite).x;
    y_obs = y_1 * sfSprite_getScale(element->sprite).y;
    size_obs[0] = x_obs;
    size_obs[1] = y_obs;
    return (size_obs);
}

int touch_obs(sfVector2f pos1, sfVector2f pos, obs *element, unsigned int *g)
{
    unsigned int *s_obs = hitbox_obs(element);
    int i = 1;

    if (element->type == 4)
        i = 2;
    if (element->type == 5)
        i = 3;
    if (pos1.x <= pos.x + g[0] && pos1.x + s_obs[0] >= pos.x + g[0]) {
        if (pos1.y <= pos.y + g[1] && pos1.y + s_obs[1] >= pos.y) {
            return (i);
        }
    }
    return (0);
}

int bonus_malus(list *l_a, obs *element)
{
    obs *first = l_a->list_enemy->first;

    if (element->type == 4)
        l_a->score = l_a->score + 50;
    if (element->type == 5)
        if (l_a->score < 50)
            l_a->score = 0;
        else
            l_a->score = l_a->score - 50;
    if (element == first)
        l_a->list_enemy->first = first->next;
    else
        while (first->next != element) {
            first = first->next;
        }
    first->next = element->next;
}

int girl_hitbox(list *l_a)
{
    sfVector2u x = sfTexture_getSize(l_a->girl->texture);
    sfVector2f s_p = sfSprite_getScale(l_a->girl->sprite);
    sfVector2f pos = sfSprite_getPosition(l_a->girl->sprite);
    sfVector2f pos1;
    unsigned int girl_coord[] = {x.x / 5 * s_p.x, x.y / 3.8 * s_p.y};
    unsigned int *s_obs;
    int end = 0;
    obs *element = l_a->list_enemy->first;

    while (element != NULL) {
        s_obs = hitbox_obs(element);
        pos1 = sfSprite_getPosition(element->sprite);
        end = touch_obs(pos1, pos, element, girl_coord);
        if (end == 2 || end == 3)
            bonus_malus(l_a, element);
        if (end == 1)
            return (1);
        element = element->next;
    }
    return (0);
}