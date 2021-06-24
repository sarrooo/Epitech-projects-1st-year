/*
** EPITECH PROJECT, 2021
** my_defeender
** File description:
** destroy monster
*/

#include "include/defender.h"

void destroy_wave(wave *monster_wave)
{
    for (int i =0; i < monster_wave->nb_monster; i++) {
        destroy_monster(monster_wave->monster, i);
    }
    free(monster_wave->monster);
    free(monster_wave);
}