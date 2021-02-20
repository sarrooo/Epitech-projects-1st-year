/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** manage window
*/

#include "include/my.h"

sfRenderWindow *create_window(sfRenderWindow *window, object *background)
{
    sfVideoMode mode = {800, 600, 32};
    sfVector2i position = {560, 240};
    sfImage *icon = sfImage_createFromFile("image/icon.png");
    const sfUint8 *pixel = sfImage_getPixelsPtr(icon);

    window = sfRenderWindow_create(mode, "Runner", sfResize | sfClose, NULL);
    sfRenderWindow_setIcon(window, 256, 256, pixel);
    sfRenderWindow_setFramerateLimit(window, 30);
    sfRenderWindow_setPosition(window, position);
    sfRenderWindow_drawSprite(window, background->sprite, NULL);
    return (window);
}