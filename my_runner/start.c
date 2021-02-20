/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** start of game
*/

#include "include/my.h"

int det_option(sfRenderWindow *window, int ac, char **av)
{
    if (!window || ac != 2) {
        my_printf("1 argument was required\n");
        my_printf("Retry with -h to see help\n");
        return (1);
    }
    if (my_strcmp(av[1], "-h") == 0) {
        description();
        return (1);
    }
    return 0;
}

void description(void)
{
    my_printf("For Compile Use Command 'make',\n");
    my_printf("For Launch Game Use './my_runner map.txt',\n\n");
    my_printf("Rules: \n");
    my_printf("In this video-game you must arrive at the end of the map \n\n");
    my_printf("You have 1 life, \n");
    my_printf("You lose if you shock an obstacle\n");
    my_printf("You win if you eat cotton candy\n");
    my_printf("You have a score and levels\n");
    my_printf("\nUser Interaction: \n");
    my_printf("SPACE => jump\n");
    my_printf("RIGHT => move forward\n");
    my_printf("LEFT => move back\n");
    my_printf("DOWN => reduce character's size\n");
    my_printf("LEFT => increase character's size\n");
    my_printf("\nMap Interaction: \n");
    my_printf("You have already 3 maps (map/) but You can customize ");
    my_printf("your map\nObstacle : 1->cat | 2->pink slim | 3->bird\n");
    my_printf("Bonus or Malus : 4->bonus (add 50 to the score) | ");
    my_printf("5->malus (remove 50 to the score)\n");
    my_printf("Indicator : E->end->cotton-candy\n\n");
    my_printf("I hope you’ll have fun, Enjoy !\n");
}

int error(list *l_a, int ac, char **av)
{
    if (ac <= 1) {
        l_a->map->map_array == NULL;
        sfMusic_destroy(l_a->music);
        sfMusic_destroy(l_a->jump_fx);
        sfRenderWindow_destroy(l_a->win);
        return (84);
    }
    read_map(ac, av, l_a);
    if (det_option(l_a->win, ac, av) == 1 || l_a->map->map_array == NULL) {
        sfMusic_destroy(l_a->music);
        sfMusic_destroy(l_a->jump_fx);
        sfRenderWindow_destroy(l_a->win);
        return (84);
    }
    return (0);
}

list *make_struct(sfRenderWindow *win, paralax *par, sfMusic *s)
{
    list *l_a = malloc(sizeof(list));

    l_a->par = par;
    l_a->win = win;
    l_a->music = s;
    l_a->jump_fx = jump_sound();
    l_a->pause = malloc(sizeof(object));
    l_a->music_but = malloc(sizeof(object));
    l_a->map = malloc(sizeof(map_obstacle));
    l_a->list_enemy = malloc(sizeof(list_obs));
    l_a->score = 0;
    l_a->level = 0;
    l_a->high_score = NULL;
}