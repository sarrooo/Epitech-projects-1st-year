/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** malloc wave
*/

#include "include/defender.h"

void malloc_wave(game_t *main_s, int nb_monster)
{
    main_s->map.monster_wave = malloc(sizeof(wave));
    main_s->map.monster_wave->monster = malloc(sizeof(monster_t) * nb_monster);
}