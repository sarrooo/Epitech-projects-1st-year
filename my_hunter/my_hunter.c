/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** Small video games like duck hunter on NES
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>
#include "lib/my.h"
#include "include/my.h"
#include <stdio.h>

void sprite_sheet_main(sfRenderWindow *win, sfIntRect *rec, int i, sfSprite *p)
{
    sfVector2f offset;
    int *max = malloc(sizeof(int) * 3);

    max[0] = 343;
    max[1] = 1029;
    max[2] = 900;
    rec = move_rect(rec, max, p, win);
    sfSprite_setTextureRect(p, *rec);
    offset.x = i;
    offset.y = 0;
    sfSprite_move(p, offset);
    sfRenderWindow_drawSprite(win, p, NULL);
}

int *main_game(sfRenderWindow *win, sfEvent event, sfSprite *a, int *score)
{
    int *b = malloc(sizeof(int) * 3);
    int *flow = speed_parrot(score[0]);
    sfSprite *pr;
    sfIntRect *rect = rect_sprite(343, 300);

    srand(time(NULL));
    b[0] = rand() % 2 + 1;
    b[1] = 0;
    b[2] = score[1];
    pr = spaw_p(b, pr, win, flow);
    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_drawSprite(win, a, NULL);
        count_seconds(win, rect, flow[0], pr);
        text_score(win, score[0]);
        text_life(win, b[2]);
        sfRenderWindow_display(win);
        if (det_end(pr, win, b, event) == 1 || b[2] >= 3)
            break;
    }
    sfSprite_destroy(pr);
    return (b);
}

int main(int ac, char **av)
{
    sfSprite *background = back_sprite();
    sfRenderWindow *window = create_window(window, background);
    sfEvent event;
    int score[2] = {0, 0};
    int *stop = malloc(sizeof(int) * 3);
    sfMusic *s = back_sound();

    if (error(window, ac, av, s) == 84)
        return EXIT_FAILURE;
    menu_play(window, background, event);
    while (sfRenderWindow_isOpen(window)) {
        stop = main_game(window, event, background, score);
        score[0] = score[0] + stop[1];
        score[1] = stop[2];
        if (score[1] >= 3)
            end_game(window, background, score, event);
        if (score[1] >= 3)
            break;
    }
    finish_game(window, background, s);
    return EXIT_SUCCESS;
}
