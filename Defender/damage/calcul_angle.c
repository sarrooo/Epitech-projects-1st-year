/*
** EPITECH PROJECT, 2021
** defender
** File description:
** calculate angle
*/

#include "../include/defender.h"

double choice_quarter(game_t *game, int im, int it, double angle)
{
    sfVector2f pos_mob =
    sfSprite_getPosition(game->map.monster_wave->monster[im].sprite);
    sfVector2f pos_tow = game->map.towers[it].position;

    if (pos_mob.x >= pos_tow.x + 100 && pos_mob.y < pos_tow.y + 100)
        angle = 360 - angle;
    if (pos_mob.x < pos_tow.x + 100 && pos_mob.y >= pos_tow.y + 100)
        angle = 180 - angle;
    if (pos_mob.x < pos_tow.x + 100 && pos_mob.y < pos_tow.y + 100)
        angle += 180;
    return (angle);
}

void calcul_angle(game_t *game, int im, int it)
{
    sfVector2f pos_tow = game->map.towers[it].position;
    sfVector2f pos_mob =
    sfSprite_getPosition(game->map.monster_wave->monster[im].sprite);
    double long_a = fabs(pos_tow.x + 100 - pos_mob.x);
    double long_b = fabs(pos_tow.y + 100 - pos_mob.y);
    double long_c = sqrt(pow(long_a, 2) + pow(long_b, 2));
    if (long_c == 0)
        long_c = 0.1;
    double angle = acos(long_a / long_c) * (180 / M_PI);
    angle = choice_quarter(game, im, it, angle);
    init_arrow(game, it, im, angle);
}