/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init map1
*/

#include "../include/defender.h"

void load_build_sound_effect(game_t *game)
{
    game->map.build.sound = sfSound_create();
    game->map.build.soundbuffer =
    sfSoundBuffer_createFromFile("./asset/build_sound.ogg");
    sfSound_setBuffer(game->map.build.sound, game->map.build.soundbuffer);
    game->map.bow = sfSound_create();
    game->map.bow_buffer =
    sfSoundBuffer_createFromFile("./asset/bow_effect.ogg");
    sfSound_setBuffer(game->map.bow, game->map.bow_buffer);
    game->map.zap = sfSound_create();
    game->map.zap_buffer = sfSoundBuffer_createFromFile("./asset/thunder.ogg");
    sfSound_setBuffer(game->map.zap, game->map.zap_buffer);
}

void destroy_build_sound_effect(game_t *game)
{
    sfSound_destroy(game->map.build.sound);
    sfSoundBuffer_destroy(game->map.build.soundbuffer);
    sfSound_destroy(game->map.bow);
    sfSoundBuffer_destroy(game->map.bow_buffer);
    sfSound_destroy(game->map.zap);
    sfSoundBuffer_destroy(game->map.zap_buffer);
}

void game_config_first_map2(game_t *game)
{
    load_wave(game);
    game->map.index_wave = 0;
    init_wave(game, game->map.wave[0]);
    game->map.if_win = 0;
    game->ex_scene = MAP1;
    game->handler_scene = &game_display_first_map;
    game->map.clock = sfClock_create();
    game->map.t_background = sfTexture_createFromFile("./asset/mp1.png", NULL);
    game->map.s_background = sfSprite_create();
    sfSprite_setTexture(game->map.s_background,
    game->map.t_background, sfTrue);
    game->scene_destroy = &game_destroy_first_map;
    init_towers_data(game);
    game_load_spell_fire(game);
    game_load_spell_freeze(game);
    load_hover_effects(game);
    init_turret_menu(game);
    game->mouse_pos.x = 800;
    game->mouse_pos.y = 800;
    game->map.towers = malloc(sizeof(turrets) * 7);
    for (int i = 0; i < 7; game->map.towers[i].type = 0, i += 1);
}

void game_config_first_map(game_t *game)
{
    init_data(game);
    game_config_first_map2(game);
    game->map.paused = -1;
    load_build_sound_effect(game);
    game->map.time = 0;
    game->map.time_base = 0;
    game->map.end_wave = 0.0;
    init_pause_scenes(game);
    info_t info;
    game->map.pause_button = malloc(sizeof(rect_but));
    info.pos = (sfVector2f){1810, 10};
    info.size = (sfVector2f){100, 100};
    info.path = "./asset/button/pause.png";
    info.callback = &set_pause_on;
    rect_button(game, info, game->map.pause_button);
}

void game_destroy_first_map(game_t *game)
{
    game->point_life = game->map.data->points_life;
    game->gold_point = game->map.data->points_gold;
    destroy_data(game);
    destroy_rect(game->map.pause_button);
    pause_destroy(game);
    destroy_build_sound_effect(game);
    destroy_turret_menu(game);
    destroy_hover_effects(game);
    game_destroy_spell(game);
    sfClock_destroy(game->map.clock);
    sfTexture_destroy(game->map.t_background);
    sfSprite_destroy(game->map.s_background);
}