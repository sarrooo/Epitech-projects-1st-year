/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** prototype of function
*/

#ifndef MY_H_

#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../lib/my.h"

typedef struct object
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f move;
    sfIntRect *rect;
}object;

typedef struct map_obstacle
{
    char **map_array;
    int nb_lines;
    int nb_cols;
}map_obstacle;

typedef struct obs obs;
typedef struct obs
{
    int type;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f move;
    sfIntRect *rect;
    int x;
    int y;
    obs *next;
}obs;

typedef struct list_obs
{
    obs *first;
    obs *end;
}list_obs;

typedef struct paralax
{
    object *b_6_2;
    object *b_6;
    object *b_5_2;
    object *b_5;
    object *b_4_2;
    object *b_4;
    object *b_3_2;
    object *b_3;
    object *b_2_2;
    object *b_2;
    object *b_1_2;
    object *b_1;
}paralax;

typedef struct list
{
    sfRenderWindow *win;
    paralax *par;
    object *girl;
    object *pause;
    object *music_but;
    map_obstacle *map;
    list_obs *list_enemy;
    sfMusic *music;
    sfMusic *jump_fx;
    float score;
    char *high_score;
    int level;
}list;

int main_game(list *l_a, sfEvent event);

sfRenderWindow *create_window(sfRenderWindow *window, object *back);

int det_option(sfRenderWindow *window, int ac, char **av);

void destroy_all(list *l_a);

int *size_element(obs *obstacle, int nb_lines, int nb_cols);

void description(void);

int error(list *l_a, int ac, char **av);

sfMouseButtonEvent analyse_ev(sfRenderWindow *win, sfEvent even);

int click_play(int *click, sfVector2f pS, sfVector2u x, sfVector2f s_p);

int *click_pos(sfRenderWindow *win, sfEvent event);

int click_button(int *click, sfVector2f pS, sfVector2u x, sfVector2f s_p);

int click_ok_play(list *l_a, sfEvent event, sfSprite *sprite, int *click);

int click_ok(list *l_a, sfEvent event, sfSprite *sprite, int *click);

sfSprite *manage_click_music(list *l_a, sfEvent event, sfSprite *sprite);

void count_seconds(sfRenderWindow *window);

sfMusic *back_sound(void);

sfMusic *jump_sound(void);

object *create_back(char *path, float offset);

object *create_back_2(char *path, float offset);

paralax *create_par(void);

void reset_paralax(list *l_a);

void draw_par(sfRenderWindow *win, paralax *par);

void move_all_par(sfRenderWindow *win, paralax *par);

void move_par(sfRenderWindow *win, object *obj);

list *make_struct(sfRenderWindow *win, paralax *par, sfMusic *music);

void struct_obs(list *l_a);

int read_map(int ac, char **av, list *l_a);

void text_start(sfRenderWindow *win);

void text_pause(sfRenderWindow *win);

void text_lose(sfRenderWindow *win);

void text_win(sfRenderWindow *win);

void text_score(sfRenderWindow *win, list *l_a);

void text_high_score(sfRenderWindow *win, list *l_a);

void text_score_final(sfRenderWindow *win, list *l_a);

void text_hight_score_final(sfRenderWindow *win, list *l_a);

void text_level(sfRenderWindow *win, list *l_a);

void text_level_final(sfRenderWindow *win, list *l_a);

void text_end_key(sfRenderWindow *win);

char *best_score(list *l_a);

int menu_pause(list *l_a, sfEvent event);

int launch_menu(list *l_a, sfEvent event);

int menu_win(list *l_a, sfEvent event);

int menu_lose(list *l_a, sfEvent event);

void draw_sprite_pause(list *l_a, sfSprite *qui, sfSprite *rel, sfSprite *res);

sfSprite *draw_play(sfRenderWindow *win);

sfSprite *draw_music(sfRenderWindow *win, sfMusic *music);

sfSprite *draw_pause(sfRenderWindow *win);

sfSprite *draw_quit(sfRenderWindow *win);

sfSprite *draw_reload(sfRenderWindow *win);

sfSprite *draw_resume(sfRenderWindow *win);

sfIntRect *rect_sprite(int width, int height);

object *create_girl(sfRenderWindow *win);

sfIntRect *rect_jump(int width, int height);

void count_seconds_jump(sfRenderWindow *window);

void jump_sprite(sfRenderWindow *win, object *girl, sfIntRect *rect);

int end_jump(list *l_a);

int manage_move(list *l_a, sfEvent event);

int jump(list *l_a, sfEvent event);

int double_jump(list *l_a, sfEvent event);

int jump_move(list *l_a, sfIntRect *rect);

int right_move(list *l_a, sfEvent event);

int left_move(list *l_a, sfEvent event);

int reduce_move(list *l_a, sfEvent event);

void move_girl(sfRenderWindow *win, object *girl, sfIntRect *rect, list *l_a);

void move_cat(obs *obstacle, sfRenderWindow *win);

void move_bird(obs *obstacle, sfRenderWindow *win);

void move_dodo(obs *obstacle, sfRenderWindow *win);

void move_obs(list *l_a);

void set_pos_obs(list *l_a);

void draw_obs(list *l_a);

int map_to_array(char *map, list *l_a);

obs *create_cat(list *l_a);

obs *create_bird(list *l_a);

obs *create_dodo(list *l_a);

void insert_end_line(list *l_a, int x, int y);

int check_end_line(list *l_a);

int girl_hitbox(list *l_a);

obs *create_bonus(list *l_a);

obs *create_malus(list *l_a);

void set_pos_bonus(list *l_a, obs *element, sfVector2f ps);

#endif
