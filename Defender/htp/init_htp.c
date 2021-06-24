/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init htp
*/

#include "../include/defender.h"

void game_config_htp2(game_t *game)
{
    load_wave(game);
    game->map.index_wave = 0;
    init_wave(game, game->map.wave[0]);
    game->map.if_win = 0;
    game->ex_scene = 7;
    game->handler_scene = &game_display_htp;
    game->map.clock = sfClock_create();
    game->map.t_background = sfTexture_createFromFile("./asset/mp1.png", NULL);
    game->map.s_background = sfSprite_create();
    sfSprite_setTexture(game->map.s_background,
    game->map.t_background, sfTrue);
    game->scene_destroy = &destroy_htp;
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

void destroy_htp(game_t *game)
{
    sfSprite_destroy(game->map.data_htp->bulle);
    sfSprite_destroy(game->map.data_htp->dark);
    sfTexture_destroy(game->map.data_htp->t_bulle);
    sfTexture_destroy(game->map.data_htp->t_dark);
    sfText_destroy(game->map.data_htp->text);
    free(game->map.data_htp->temp);
    free(game->map.data_htp->str);
    sfSound_destroy(game->map.data_htp->tping);
    sfSoundBuffer_destroy(game->map.data_htp->t_buffer);
    free(game->map.data_htp);
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

void init_htp2(game_t *game)
{
    game->map.data_htp = malloc(sizeof(data_htp));
    game->map.data_htp->i = 0;
    game->map.data_htp->total_step = 5;
    game->map.data_htp->current_step = 0;
    game->map.data_htp->current_timer = 0;
    game->map.data_htp->bulle = sfSprite_create();
    game->map.data_htp->dark = sfSprite_create();
    game->map.data_htp->t_bulle =
    sfTexture_createFromFile("./asset/table_2.png", NULL);
    game->map.data_htp->t_dark =
    sfTexture_createFromFile("./asset/bg/dark.png", NULL);
    sfSprite_setTexture(game->map.data_htp->bulle, game->map.data_htp->t_bulle,
    sfTrue);
    sfSprite_setTexture(game->map.data_htp->dark, game->map.data_htp->t_dark,
    sfTrue);
    game->map.data_htp->position = (sfVector2f){20, 500};
    sfSprite_setPosition(game->map.data_htp->bulle,
    game->map.data_htp->position);
    game->map.data_htp->started = 0;
    game->map.data_htp->titime = 0;
}

void init_htp(game_t *game)
{
    init_htp2(game);
    game->map.data_htp->finished = 0;
    game->map.data_htp->tping = sfSound_create();
    game->map.data_htp->t_buffer =
    sfSoundBuffer_createFromFile("./asset/typing.ogg");
    sfSound_setBuffer(game->map.data_htp->tping, game->map.data_htp->t_buffer);
    sfSound_setLoop(game->map.data_htp->tping, sfTrue);
    read_dialogue(game, "./htp/dialogue_0.txt");
    game->map.data_htp->text = sfText_create();
    sfText_setFont(game->map.data_htp->text, game->map.data->font);
    sfText_setColor(game->map.data_htp->text, sfBlack);
    sfText_setString(game->map.data_htp->text, "");
    sfText_setCharacterSize(game->map.data_htp->text, 40);
    sfText_setPosition(game->map.data_htp->text, (sfVector2f){70, 530});
}

void game_config_htp(game_t *game)
{
    init_data(game);
    game_config_htp2(game);
    game->map.paused = -1;
    load_build_sound_effect(game);
    game->map.time = 0;
    game->map.time_base = 0;
    init_pause_scenes(game);
    info_t info;
    game->map.pause_button = malloc(sizeof(rect_but));
    info.pos = (sfVector2f){1810, 10};
    info.size = (sfVector2f){100, 100};
    info.path = "./asset/button/pause.png";
    info.callback = &set_pause_on;
    rect_button(game, info, game->map.pause_button);
    init_htp(game);
}