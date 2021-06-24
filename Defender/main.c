/*
** EPITECH PROJECT, 2021
** dev
** File description:
** defender
*/

#include "./include/defender.h"

void game_destroy(game_t *game)
{
    if (game->scene_destroy != NULL)
        game->scene_destroy(game);
    sfRenderWindow_destroy(game->win);
    sfMusic_destroy(game->music);
    free(game);
}

void game_create(game_t *game)
{
    game->framerate = 60;
    game->volume = 50;
    read_scoreboard(game);
    game->mode = (sfVideoMode){1920, 1080, 32};
    game->win = sfRenderWindow_create(game->mode, "Defender",
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->win, game->framerate);
    init_music(game);
    game->current_scene = MENU;
    game->ex_scene = 0;
    game->scene_config = &init_menu_scenes;
    game->scene_destroy = NULL;
}

int main(int argc, char **argv)
{
    game_t *game = malloc(sizeof(game_t) * 1);

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        helper();
        return (0);
    }
    game_create(game);
    game_start(game);
    game_destroy(game);
}