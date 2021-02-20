/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** prototype of function
*/

#include <SFML/Audio.h>

#ifndef MY_H_

int my_printf(char *str, ...);

typedef struct framebuffer framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);

void framebuffer_destroy(framebuffer_t *framebuffer);

sfRenderWindow *create_window(sfRenderWindow *window, sfSprite *background);

sfSprite *sprite_sheet_parrot(sfRenderWindow *window, sfIntRect *rect);

sfSprite *sprite_sheet_parrot2(sfRenderWindow *window, sfIntRect *rect);

sfIntRect *move_rect(sfIntRect *rect, int *max, sfSprite *p, sfRenderWindow *w);

void count_seconds(sfRenderWindow *win, sfIntRect *rec, int i, sfSprite *p);

int score(sfSprite *p, sfRenderWindow *win, sfEvent event, int *b);

sfIntRect *rect_sprite(int width, int height);

sfSprite *back_sprite(void);

void sprite_sheet_main(sfRenderWindow *win, sfIntRect *rec, int i, sfSprite *p);

sfSprite *spaw_p(int *b, sfSprite *pr, sfRenderWindow *win, int *flow);

int *main_game(sfRenderWindow *win, sfEvent event, sfSprite *b, int *score);

void close_window(sfRenderWindow *window);

void manage_mouse_click(sfMouseButtonEvent event);

sfMouseButtonEvent analyse_events(sfRenderWindow *window, sfEvent event);

void description(void);

int my_strcmp(char const *s1, char const *s2);

char int_str(int nb, int base);

char *str_int(int nb);

char *str_cat(char *s1, char *s2);

sfText *text_score(sfRenderWindow *win, int score);

sfText *text_life(sfRenderWindow *win, int score);

int *speed_parrot(int score);

sfSprite *play(sfRenderWindow *win);

sfSprite *replay(sfRenderWindow *win);

sfSprite *quit(sfRenderWindow *win);

int det_end(sfSprite *parrot, sfRenderWindow *win, int *b, sfEvent event);

int end_game(sfRenderWindow *win, sfSprite *back, int *score, sfEvent event);

int *click_end(sfRenderWindow *win, sfEvent event);

int quit_game(sfRenderWindow *win, int *score, sfEvent event, int *click);

int det_option(sfRenderWindow *window, int ac, char **av);

int menu_play(sfRenderWindow *win, sfSprite *back, sfEvent event);

void text_end(sfRenderWindow *win, int *score);

void text_start(sfRenderWindow *win);

sfMusic *back_sound(void);

sfMusic *shoot_sound(void);

void finish_game(sfRenderWindow *win, sfSprite *back, sfMusic *m);

int error(sfRenderWindow *window, int ac, char **av, sfMusic *s);

sfText *text_best(sfRenderWindow *win, int score, char *best_str);

char *score_files(void);

#endif /*MY_H_*/
