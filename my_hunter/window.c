/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** Manage action on window
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Config.h>
#include <SFML/Audio.h>
#include "include/my.h"

sfRenderWindow *create_window(sfRenderWindow *window, sfSprite *background)
{
    sfVideoMode mode = {1400, 800, 32};
    sfVector2i position = {260, 140};

    window = sfRenderWindow_create(mode, "Hunter", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 15);
    sfRenderWindow_setPosition(window, position);
    sfRenderWindow_drawSprite(window, background, NULL);
    return (window);
}

sfSprite *back_sprite(void)
{
    sfSprite *back_sprite = sfSprite_create();
    sfTexture *back_tex = sfTexture_createFromFile("image/jungle_m.jpg", NULL);
    sfVector2f size;

    size.x = 0.20295738;
    size.y = 0.25086234;
    sfSprite_setScale(back_sprite, size);
    sfSprite_setTexture(back_sprite, back_tex, sfTrue);
    return (back_sprite);
}

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}
