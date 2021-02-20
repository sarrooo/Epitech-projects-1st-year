/*
** EPITECH PROJECT, 2020
** buffer
** File description:
** buffer create and destroy
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Config.h>
#include <SFML/Audio.h>
#include "include/my.h"

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};

typedef struct framebuffer framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *window = malloc(sizeof(framebuffer_t));

    window->pixels = malloc(sizeof(sfUint8) * (width * height * 4));
    window->width = width;
    window->height = height;
    return (window);
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer);
}
