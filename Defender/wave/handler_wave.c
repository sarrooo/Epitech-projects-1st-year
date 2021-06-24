/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** handler for monster wave
*/

#include "../include/defender.h"

void manage_damage_monster(game_t *main_s, int index_point, int nb_p, int i)
{
    int damage = main_s->map.monster_wave->monster[i].damage;
    int reward = main_s->map.monster_wave->monster[i].reward;

    if (nb_p != index_point)
        move_monster(main_s, main_s->map.monster_wave->monster, i);
    else {
        main_s->map.monster_wave->monster[i].if_dead = 1;
        main_s->map.data->points_life -= damage;
        if (main_s->map.data->points_life <= 0) {
            main_s->map.if_win = 2;
            main_s->current_scene = 6;
            main_s->scene_config = &init_win_screen_scenes;
        }
    }
    if (main_s->map.monster_wave->monster[i].health <= 0) {
        main_s->map.monster_wave->monster[i].if_dead = 1;
        main_s->map.data->points_gold += reward;
    }
}

void move_animation_monster(game_t *main_s, int i)
{
    int nb_points = main_s->map.monster_wave->monster[i].nb_point;
    int index_point = main_s->map.monster_wave->monster[i].index_point;
    float last_move = main_s->map.monster_wave->monster[i].last_move;
    int damage = main_s->map.monster_wave->monster[i].damage;
    int reward = main_s->map.monster_wave->monster[i].reward;

    if (main_s->map.time > last_move + (1.0/30.0)) {
        main_s->map.monster_wave->monster[i].last_move = main_s->map.time;
        animation_monster(main_s, main_s->map.monster_wave->monster, i);
        manage_damage_monster(main_s, index_point, nb_points, i);
    }
}

void switch_wave(game_t *main_s)
{
    if (main_s->map.end_wave == 0.0) {
        main_s->map.end_wave = main_s->map.time;
        return;
    }
    if (main_s->map.time < main_s->map.end_wave + 5)
        return;
    main_s->map.index_wave++;
    if (main_s->map.wave[main_s->map.index_wave] == NULL) {
        destroy_wave(main_s->map.monster_wave);
        main_s->map.if_win = 1;
        main_s->current_scene = 6;
        main_s->gold_point = main_s->map.data->points_gold;
        main_s->scene_config = &init_win_screen_scenes;
        main_s->map.end_wave = 0.0;
    }
    else {
        destroy_wave(main_s->map.monster_wave);
        main_s->map.data->points_wave++;
        init_wave(main_s, main_s->map.wave[main_s->map.index_wave]);
        main_s->map.end_wave = 0.0;
    }
}

void handler_wave(game_t *main_s)
{
    int nb_monster_live = 0;
    float end_wave;

    main_s->map.time = main_s->map.time_base;
    main_s->map.time += get_time(main_s);
    for (int i = 0; i < main_s->map.monster_wave->nb_monster; i++) {
        if (main_s->map.monster_wave->monster[i].if_dead == 0) {
            apply_damage(main_s, i);
            move_animation_monster(main_s, i);
            refresh_health_bar(main_s->map.monster_wave->monster, i);
            draw_monster(main_s, i);
            nb_monster_live++;
        }
    }
    put_attack(main_s);
    if (nb_monster_live == 0) {
        switch_wave(main_s);
    }
}