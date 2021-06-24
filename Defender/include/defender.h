/*
** EPITECH PROJECT, 2021
** fire
** File description:
** fire
*/

#ifndef defender
#define defender

//Includes

#include "mikael.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

//MACRO

#define ARCHER_1 1
#define ARCHER_2 2
#define MAGICIAN_1 3
#define MAGICIAN_2 4

#define LOW 1
#define MEDIUM 0.7
#define FAST 0.5

#define SHORT 50
#define NORMAL 70
#define LONG 90

#define MENU 1
#define SETTINGS 2
#define MAP1 3
#define MAP2 4
#define MAP3 5

//STRUCTURES

typedef struct game_t game_t;
typedef struct rect_but rect_but;
typedef struct circle_but circle_but;
typedef struct wave wave;
typedef struct monster_t monster_t;

typedef struct data_htp {
    int current_step;
    int total_step;
    sfSprite *bulle;
    sfTexture *t_bulle;
    sfVector2f position;
    sfSprite *dark;
    sfTexture *t_dark;
    char *str;
    char *temp;
    sfText *text;
    float current_timer;
    sfSound *tping;
    sfSoundBuffer *t_buffer;
    int finished;
    int i;
    int started;
    float titime;
} data_htp;

typedef struct projectile {
    sfSprite *sprite;
    sfVector2f position;
    float step_total;
    float last_move;
    float step_x;
    float step_y;
    float current_step;
    int target;
} projectile_t;

typedef struct tower_stat {
    int damage;
    float attack_speed;
    int range;
} tower_stat;

typedef struct towers_stat {
    tower_stat archery1;
    tower_stat archery2;
    tower_stat magic1;
    tower_stat magic2;
} towers_stat;

typedef struct data {
    sfSprite *s_gold;
    sfTexture *t_gold;
    sfSprite *s_wave;
    sfTexture *t_wave;
    sfFont *font;
    sfText *gold;
    sfText *life;
    sfText *wave;
    int life_max;
    int points_life;
    int points_gold;
    int wave_max;
    int points_wave;
    int start_gold;
} data_t;

typedef struct turret_pos_t {
    sfSprite *sprite;
    sfTexture *texture;
    int x1;
    int x2;
    int y1;
    int y2;
} turret_pos_t;

typedef struct turrets {
    int type;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
    int damage;
    int range;
    float attack_speed;
    int in_attack;
    sfTexture* t_projectile;
    projectile_t *arrow;
    sfSprite *thunder;
    float timer;
} turrets;

typedef struct spell_t {
    sfSprite *sprite_spell;
    sfTexture *texture_spell;
    sfSprite *icone;
    sfTexture *t_icone;
    sfIntRect rect;
    sfVector2f position;
    sfSprite *cursor;
    sfTexture *cursor_texture;
    int targeting;
    int damage;
    int animation;
    int available;
    float last_move;
    sfSound *sound;
    sfSoundBuffer *soundbuffer;
} spell_t;

typedef struct turret_menu {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    int clicked;
    sfSprite *sell;
    sfTexture *t_sell;
    sfVector2f sell_pos;
    int sell_clicked;
} turret_menu;

typedef struct build_sound {
    sfSound *sound;
    sfSoundBuffer *soundbuffer;
} build_sound;

typedef struct scene_t{
    sfClock* clock;
    sfSprite *s_background;
    sfTexture *t_background;
    spell_t fireball;
    spell_t freeze;
    turret_pos_t *turret_pos;
    turret_menu turret_menu;
    turrets *towers;
    build_sound build;
    int paused;
    float time;
    float time_base;
    wave *monster_wave;
    rect_but *pause_button;
    data_t *data;
    towers_stat* stats;
    sfSound *bow;
    sfSoundBuffer *bow_buffer;
    sfSound *zap;
    sfSoundBuffer *zap_buffer;
    char **wave;
    int index_wave;
    int if_win;
    float end_wave;
    data_htp *data_htp;
} scene_t;

typedef struct rect_but
{
    char *name;
    sfRectangleShape *button;
    sfTexture *texture;
    sfVector2f original_pos;
    void (*callback)(game_t *main_s, rect_but but);
}rect_but;

typedef struct circle_but
{
    char *name;
    sfCircleShape *button;
    sfTexture *texture;
    sfVector2f original_pos;
    void (*callback)(game_t *main_s, circle_but but);
}circle_but;

typedef struct object_t
{
    sfSprite *sprite;
    sfTexture *texture;
}object_t;

typedef struct text_t
{
    sfText *text;
    sfFont *font;
}text_t;

typedef struct menu_t
{
    rect_but *music_but;
    rect_but *sound_but;
    rect_but *setting_but;
    rect_but *htp_but;
    circle_but *play_but;
    circle_but *quit_but;
    object_t *background;
    object_t *logo;
    rect_but *scoreboard_button;
}menu_t;

typedef struct pause_t
{
    object_t *dark;
    object_t *plank;
    object_t *rope_1;
    object_t *rope_2;
    object_t *music_bar_bg;
    object_t *music_bar;
    object_t *rate_bar_bg;
    object_t *rate_bar;
    circle_but *music_minus;
    circle_but *music_plus;
    circle_but *rate_minus;
    circle_but *rate_plus;
    circle_but *resume;
    rect_but *menu;
    rect_but *quit;
    text_t *header;
    text_t *music_volume;
    text_t *sound_volume;
}pause_t;

typedef struct setting_t
{
    object_t *plank;
    object_t *header;
    object_t *dark;
    object_t *rope_1;
    object_t *rope_2;
    object_t *music_bar_bg;
    object_t *music_bar;
    object_t *rate_bar_bg;
    object_t *rate_bar;
    circle_but *quit_but;
    circle_but *music_minus;
    circle_but *music_plus;
    circle_but *rate_minus;
    circle_but *rate_plus;
    rect_but *on_off_button;
    rect_but *on_off_button_2;
    text_t *music_txt;
    text_t *sound_txt;
    text_t *music_volume;
    text_t *graphic;
    object_t *background;
}setting_t;

typedef struct win_screen_t
{
    object_t *background;
    object_t *plank;
    object_t *header;
    object_t *dark;
    object_t *bg_star;
    object_t *star;
    rect_but *menu_button;
    rect_but *replay_button;
    circle_but *quit_button;
    text_t *message_1;
    text_t *message_2;
    object_t *plank_scoreboard;
    text_t *header_scoreboard;
    text_t *first_place;
    text_t *second_place;
    text_t *third_place;
    text_t *fourth_place;
    text_t *fifth_place;
    text_t *score_txt;
    sfMusic *sound;
}win_screen_t;

typedef struct scoreboard_t
{
    object_t *background;
    object_t *plank;
    object_t *dark;
    circle_but *quit_button;
    text_t *header;
    text_t *first_place;
    text_t *second_place;
    text_t *third_place;
    text_t *fourth_place;
    text_t *fifth_place;
}scoreboard_t;

typedef struct game_t {
    sfRenderWindow *win;
    sfVideoMode mode;
    sfVector2f mouse_pos;
    sfEvent event;
    int ex_scene;
    int framerate;
    int current_scene;
    sfMusic *music;
    float volume;
    void (*handler_scene)(game_t*);
    void (*scene_destroy)(game_t*);
    void (*scene_config)(game_t*);
    scene_t map;
    menu_t *menu_scene;
    setting_t *menu_setting;
    pause_t *menu_pause;
    win_screen_t *win_screen;
    scoreboard_t *scoreboard;
    int point_life;
    int gold_point;
    char **scoreboard_point;
} game_t;

typedef struct info_t
{
    char *path;
    char *str;
    sfColor color;
    sfVector2f pos;
    sfVector2f size;
    sfVector2f scale;
    int radian;
    void (*callback)();
}info_t;

typedef struct point
{
    sfVector2f max_point;
    sfVector2f move;
}point;

typedef struct wave
{
    int nb_monster;
    monster_t *monster;
}wave;

typedef struct monster_t
{
    sfSprite *sprite;
    sfTexture *texture;
    int nb_point;
    int index_point;
    sfVector2f spawn_point;
    point *point_map;
    sfIntRect rect;
    int health_original;
    int health;
    float speed;
    float speed_max;
    int reward;
    int damage;
    float last_move;
    int offset_bar;
    int if_dead;
    int electrise;
    float middle;
    object_t *bar;
    object_t *bar_bg;
}monster_t;

typedef struct monster_info
{
    char *path;
    point *point_map;
    sfIntRect rect;
    sfVector2f scale;
    sfVector2f spaw_point;
    int nb_point;
    int index_point;
    int index;
    int health;
    float speed;
    int reward;
    int damage;
}monster_info;

//PROTOTYPES

//MAINGAME
void game_start(game_t *game);

//TOOLS
float get_time(game_t *game);

//HTP
void game_config_htp(game_t *game);
void load_build_sound_effect(game_t *game);
void game_display_htp(game_t *game);
void handle_event_first_map(game_t *game);
void handle_event_first_map2(game_t *game);
void game_display_first_map(game_t *game);
void game_display_first_map2(game_t *game);
void destroy_htp(game_t *game);
void init_htp(game_t *game);
void game_display_htp2(game_t *game);
void handle_over_freeze(game_t *game);
void handle_over_fire(game_t *game);
void game_display_htp3(game_t *game);
void load_dark_step2(game_t *game, char* filepath);
void game_display_htp4(game_t *game);
void game_display_htp5(game_t *game);
void game_display_htp6(game_t *game);
void game_display_htp7(game_t *game);
void handle_pause_htp1(game_t *game);
void destroy_build_sound_effect(game_t *game);
void handle_target_fire(game_t *game);
void display_typing_0(game_t *game);

//FIRSTMAP
void game_destroy_first_map(game_t *game);
void game_config_first_map(game_t *game);
void game_display_first_map(game_t *game);
void handle_pause(game_t *game);

//SPELL
void game_load_spell_fire(game_t *game);
void game_load_spell_freeze(game_t *game);
void game_load_spell_sound_freeze(game_t *game);
void game_load_spell_sound_fire(game_t *game);
void handle_hover_spell(game_t *game);
void handle_targeting(game_t *game);
void spell_cursor(game_t *game);
void game_destroy_spell(game_t *game);
void set_cooldown(game_t *game);
void animation_spell_fire(game_t *game);
void animation_spell_freeze(game_t *game);
void game_destroy_spell(game_t *game);
void set_cooldown_fire(game_t *game);
void set_cooldown_freeze(game_t *game);
void handle_target_freeze(game_t *game);

//EFFECTS
void load_hover_effects(game_t *game);
void destroy_hover_effects(game_t *game);

//EVENT
void handle_move(game_t *game, sfMouseMoveEvent event);

//TURRET
void display_turrets(game_t *game);
void handle_hover_turret(game_t *game);
void destroy_turret_menu(game_t *game);
void init_turret_menu(game_t *game);
void display_turret_menu(game_t *game);
void display_buy_menu(game_t *game);
void choice_turret(game_t *game);
void init_archery_1(game_t *game, int index, sfVector2f position);
void init_archery_2(game_t *game, int index, sfVector2f position);
void init_magic_1(game_t *game, int index, sfVector2f position);
void init_magic_2(game_t *game, int index, sfVector2f position);
void destroy_tower(game_t *game, int index);
void display_turrets(game_t *game);
void init_towers_data(game_t *game);
void destroy_towers_data(game_t *game);
int read_parser_xml(game_t *game, char *filepath);
void check_integrity_of_data(game_t *game);
void init_default_settings(game_t *game);
void init_archery_11(game_t *game, int index, sfVector2f position);
void init_archery_22(game_t *game, int index, sfVector2f position);
void init_magic_11(game_t *game, int index, sfVector2f position);
void init_magic_22(game_t *game, int index, sfVector2f position);
void display_sell_menu(game_t *game);
void display_menu_sell(game_t *game);
int choose_action(game_t *game);

//DAMAGE
void apply_damage(game_t *game, int i);
void calcul_angle(game_t *game, int im, int it);
void init_arrow(game_t *game, int it, int im, double angle);
void handler_arrow(game_t *game);
void destroy_arrow(game_t *game, int it);
void move_arrow(game_t *game, int it);
void init_thunder(game_t *game, int it);
void destroy_thunder(game_t *game, int it);
void apply_thunder(game_t *game, int it, int im);
void put_attack(game_t *game);
void game_animation(game_t *game, int it);
int check_if_monster_is_in_range2(game_t *game, int it, int im);

//INIT BUTTON & OBJECT & TEXT
void circle_button(game_t *main_s, info_t info, circle_but *but);
void rect_button(game_t *main_s, info_t info, rect_but *but);
void init_object(game_t *main_s, info_t info, object_t *obj);
void init_text(game_t *main_s, info_t info, text_t *text);
void init_music(game_t *main_s);

//DATA
void init_data(game_t *game);
void destroy_data(game_t *game);
void set_text(game_t *game);
void read_dialogue(game_t* game, char *filepath);

//RECT BUTTON
int is_rect_hover(game_t *main_s, sfRectangleShape *button, sfVector2f clic);
int is_rect_clic(game_t *main_s, sfRectangleShape *button, sfVector2f clic);
void animation_rect_clic(game_t *main_s, rect_but but);
void set_rect_button(char *path, rect_but *but);
void set_rect_pos(sfRectangleShape *but, int x, int y);
void rect_clic_call(game_t *main_s, rect_but *object, sfVector2f clic);
void destroy_rect(rect_but *object);
void animation_rect_none(game_t *main_s, rect_but *but);

//CIRCLE BUTTON
int is_circle_hover(game_t *main_s, sfCircleShape *button, sfVector2f clic);
int is_circle_clic(game_t *main_s, sfCircleShape *button, sfVector2f clic);
void animation_circle_clic(game_t *main_s, circle_but but);
void set_circle_button(char *path, circle_but *but);
void set_circle_pos(sfCircleShape *but, int x, int y);
void circle_clic_call(game_t *main_s, circle_but *object, sfVector2f clic);
void destroy_circle(circle_but *object);
void animation_circle_none(game_t *main_s, circle_but *but);

//OBJECT
void destroy_object(object_t *object);

//TEXT
void destroy_text(text_t *text);

//BAR
void rect_music_bar(sfMusic *music, object_t * bar);
void rect_rate_bar(game_t *main_s, object_t *bar);
void rect_sound_bar(game_t *main_s, object_t *bar);

//MAIN MENU
void malloc_menu(game_t *main_s);
void set_background(game_t *main_s, int index_scene, char *path);
void init_menu_scenes(game_t *main_s);
void destroy_menu_scene(game_t *main_s);
void draw_menu(game_t *main_s);
void check_menu_event(game_t *main_s);
void check_menu_button(game_t *main_s);
void check_menu_hover(game_t *main_s, sfVector2f pos_mouse);
void check_menu_clic(game_t *main_s, sfVector2f pos_mouse);
void menu_rect_button(game_t *main_s);
void menu_circle_button(game_t *main_s);
void menu_object_button(game_t *main_s);
void menu_destroy(game_t *main_s);
void handler_menu(game_t *main_s);
void menu_check_button_none(game_t *main_s);
void malloc_menu(game_t *main_s);

//MAIN MENU BUTTON FUNCTION
void play_stop_music(game_t *main_s);
void play_stop_fx(game_t *main_s);
void play_game(game_t *main_s);
void htp_menu(game_t *main_s);
void close_window(game_t *main_s);
void update_music_button_menu(game_t *main_s);
void update_sound_button_menu(game_t *main_s);
void open_scoreboard(game_t *main_s);

//SETTING MENU
void malloc_setting(game_t *main_s);
void setting_menu(game_t *main_s);
void init_setting_scenes(game_t *main_s);
void draw_setting(game_t *main_s);
void check_setting_event(game_t *main_s);
void check_setting_hover(game_t *main_s, sfVector2f pos_mouse);
void check_setting_clic(game_t *main_s, sfVector2f pos_mouse);
void setting_object_button(game_t *main_s);
void setting_circle_button(game_t *main_s);
void setting_rect_button(game_t *main_s);
void setting_text(game_t *main_s);
void setting_destroy(game_t *main_s);
void handler_setting(game_t *main_s);
void setting_check_button_none(game_t *main_s);
void malloc_setting(game_t *main_s);

//SETTING MENU BUTTON FUNCTION
void on_off_music(game_t *main_s);
void on_off_sound(game_t *main_s);
void raise_music_volume(game_t *main_s);
void reduce_music_volume(game_t *main_s);
void raise_framerate(game_t *main_s);
void reduce_framerate(game_t *main_s);
void quit_setting(game_t *main_s);
void update_button_sound_setting(game_t *main_s);
void update_button_music_setting(game_t *main_s);

//PAUSE MENU
void set_pause_on(game_t *game, rect_but boutton);
void malloc_pause(game_t *main_s);
void pause_object_button(game_t *main_s);
void init_pause_scenes(game_t *main_s);
void draw_pause(game_t *main_s);
void handler_pause(game_t *main_s, int on);
void check_pause_event(game_t *main_s, int on);
void pause_circle_button(game_t *main_s);
void pause_rect_button(game_t *main_s);
void pause_text(game_t *main_s);
void check_pause_hover(game_t *main_s, sfVector2f pos_mouse);
void check_pause_clic(game_t *main_s, sfVector2f pos_mouse);
void pause_destroy(game_t *main_s);
void pause_check_button_none(game_t *main_s);
void malloc_pause(game_t *main_s);

//PAUSE MENU BUTTON FUNCTION
void raise_sound_volume_pause(game_t *main_s);
void reduce_sound_volume_pause(game_t *main_s);
void raise_music_volume_pause(game_t *main_s);
void reduce_music_volume_pause(game_t *main_s);
void resume_game(game_t *main_s);
void menu_game_pause(game_t *main_s);
void quit_game_pause(game_t *main_s);

//MONSTER
void init_monster(game_t *main_s, monster_info info, monster_t *monster);
void animation_monster(game_t *main_s, monster_t *monster, int index);
void move_monster(game_t *main_s, monster_t *monster, int index);
void set_orientation_monster(monster_t *monster, int index);
void init_monster_normal(game_t *main_s, monster_info info, monster_t *monstr);
void init_monster_fast(game_t *main_s, monster_info info, monster_t *monster);
void init_monster_tank(game_t *main_s, monster_info info, monster_t *monster);
void init_monster_boss(game_t *main_s, monster_info info, monster_t *monster);
void destroy_monster(monster_t *monster, int index);
void win_screen_check_button_none(game_t *main_s);
void check_win_screen_hover(game_t *main_s, sfVector2f pos_mouse);
void check_win_screen_clic(game_t *main_s, sfVector2f pos_mouse);
void draw_monster(game_t *main_s, int i);

//MONSTER HEALTH BAR
void init_bar_healt(game_t *main_s, monster_t *monster, monster_info info_1);
void refresh_health_bar(monster_t *monster, int index);

//WAVE
void malloc_wave(game_t *main_s, int nb_monster);
void init_wave(game_t *main_s, char *str);
void handler_wave(game_t *main_s);
void destroy_wave(wave *monster_wave);
char **load_wave(game_t *main_s);
void destroy_wave_str(game_t *main_s);

//POINT MAP
point *init_point_map1(int nb_points, float speed);
point init_point(float x_max, float y_max, float vector_x, float vector_y);
point *init_point_map1_boss(int nb_points, float speed);
point *init_point_map1_tank(int nb_points, float speed);
point *init_point_map1_normal(int nb_points, float speed);
point *init_point_map1_fast(int nb_points, float speed);

//AUXILIARY FONCTION
sfVector2f int_to_sfvector2f(int x, int y);
sfIntRect int_to_sfintrect(int left, int top, int width, int height);

//WIN SCREEN
void init_win_screen_scenes(game_t *main_s);
void malloc_win_screen(game_t *main_s);
void draw_win_screen(game_t *main_s);
void destroy_win_screen(game_t *main_s);
void handler_win_screen(game_t *main_s);
void check_win_screen_event(game_t *main_s);
void win_screen_object(game_t *main_s);
void win_screen_rect_button(game_t *main_s);
void win_screen_circle_button(game_t *main_s);
void win_screen_text(game_t *main_s);
void win_screen_scoreboard_object(game_t *main_s);
void win_screen_scoreboard_text(game_t *main_s);
void win_screen_sound(game_t *main_s);

//WIN SCREEN MENU BUTTON FUNCTION
void restart_game(game_t *main_s);
void return_to_menu(game_t *main_s);
void close_window_win_screen(game_t *main_s);

//SCOREBOARD
void malloc_scoreboard(game_t *main_s);
void scoreboard_destroy(game_t *main_s);
void draw_scoreboard(game_t *main_s);
void check_scoreboard_event(game_t *main_s);
void scoreboard_object_button(game_t *main_s);
void scoreboard_circle_button(game_t *main_s);
void scoreboard_text(game_t *main_s);
void scoreboard_check_button_none(game_t *main_s);
void check_scoreboard_clic(game_t *main_s, sfVector2f pos_mouse);
void check_scoreboard_hover(game_t *main_s, sfVector2f pos_mouse);
void handler_scoreboard(game_t *main_s);
void init_scoreboard(game_t *main_s);
void scoreboard_check_button_none(game_t *main_s);

//SCOREBOARD FUNCTION BUTTON
void return_to_menu_scoreboard(game_t *main_s);

//SCORE
void read_scoreboard(game_t *main_s);
void sort_score(char **score);
char *str_cat_score(char *s1, char *s2);
void score_win_screen(game_t *main_s);

void helper(void);

#endif /* !defender */
