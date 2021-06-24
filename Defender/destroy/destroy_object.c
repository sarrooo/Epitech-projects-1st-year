/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** function for destroy text_t, circle_t, obj_t, rectt
*/

#include "include/defender.h"

void destroy_text(text_t *text)
{
    sfFont_destroy(text->font);
    sfText_destroy(text->text);
    free(text);
}

void destroy_circle(circle_but *object)
{
    sfCircleShape_destroy(object->button);
    free(object->name);
    sfTexture_destroy(object->texture);
    free(object);
}

void destroy_object(object_t *object)
{
    sfSprite_destroy(object->sprite);
    sfTexture_destroy(object->texture);
    free(object);
}

void destroy_rect(rect_but *object)
{
    sfRectangleShape_destroy(object->button);
    free(object->name);
    sfTexture_destroy(object->texture);
    free(object);
}
