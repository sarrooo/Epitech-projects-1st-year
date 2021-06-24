/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init_monster
*/

#include "../include/defender.h"

int count_nb_monster(char *str)
{
    int nb_monster = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '1')
            nb_monster++;
        if (str[i] == '2')
            nb_monster++;
        if (str[i] == '3')
            nb_monster++;
        if (str[i] == '4')
            nb_monster++;
    }
    return (nb_monster);
}

void manage_spawn_monster(game_t *main_s, char *str, monster_info info)
{
    int index = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        info.spaw_point.y += 50;
        if (str[i] >= '1' && str[i] <= '4')
            info.index = index++;
        if (str[i] == '1')
            init_monster_fast(main_s, info,
            main_s->map.monster_wave->monster);
        if (str[i] == '2')
            init_monster_normal(main_s, info,
            main_s->map.monster_wave->monster);
        if (str[i] == '3')
            init_monster_tank(main_s, info,
            main_s->map.monster_wave->monster);
        if (str[i] == '4')
            init_monster_boss(main_s, info,
            main_s->map.monster_wave->monster);
    }
}

void init_wave(game_t *main_s, char *str)
{
    int index = 0;
    int nb_monster = count_nb_monster(str);
    monster_info info;

    malloc_wave(main_s, nb_monster);
    main_s->map.monster_wave->nb_monster = nb_monster;
    info.index = 0;
    info.spaw_point = int_to_sfvector2f(1700, 900);
    main_s->point_life = main_s->map.data->points_life;
    manage_spawn_monster(main_s, str, info);
}