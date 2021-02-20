/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** sprite of obstacle
*/

#include "include/my.h"

obs *create_cat(list *l_a)
{
    obs *obj = malloc(sizeof(obs));
    sfVector2f size = {0.5, 0.5};
    sfVector2f pos = {15, 376};
    sfVector2f move_c = l_a->par->b_1->move;

    obj->type = 1;
    obj->rect = malloc(sizeof(sfIntRect));
    obj->rect->height = 105;
    obj->rect->width = 200;
    obj->rect->top = 0;
    obj->rect->left = 200;
    obj->move = move_c;
    obj->texture = sfTexture_createFromFile("image/cat.png", NULL);
    sfTexture_setSmooth(obj->texture, sfTrue);
    obj->sprite = sfSprite_create();
    sfSprite_setScale(obj->sprite, size);
    sfSprite_setPosition(obj->sprite, pos);
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setTextureRect(obj->sprite, *obj->rect);
    return (obj);
}

obs *create_bird(list *l_a)
{
    obs *obj = malloc(sizeof(obs));
    sfVector2f size = {0.35, 0.35};
    sfVector2f pos = {0, 0};
    sfVector2f move_c = l_a->par->b_1->move;

    obj->type = 3;
    obj->rect = rect_sprite(360, 360);
    obj->texture = sfTexture_createFromFile("image/bird.png", NULL);
    obj->sprite = sfSprite_create();
    obj->move = move_c;
    sfTexture_setSmooth(obj->texture, sfTrue);
    sfSprite_setScale(obj->sprite, size);
    sfSprite_setPosition(obj->sprite, pos);
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setTextureRect(obj->sprite, *obj->rect);
    return (obj);
}

obs *create_dodo(list *l_a)
{
    obs *obj = malloc(sizeof(obs));
    sfVector2f size = {0.25, 0.25};
    sfVector2f pos = {15, 300};
    sfVector2f move_c = l_a->par->b_1->move;

    obj->type = 2;
    obj->rect = rect_sprite(109, 88);
    obj->texture = sfTexture_createFromFile("image/pink2.png", NULL);
    sfTexture_setSmooth(obj->texture, sfTrue);
    obj->move = move_c;
    obj->sprite = sfSprite_create();
    sfSprite_setPosition(obj->sprite, pos);
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setTextureRect(obj->sprite, *obj->rect);
    return (obj);
}

void draw_obs(list *l_a)
{
    obs *obstacle = l_a->list_enemy->first;

    while (obstacle != NULL) {
        sfRenderWindow_drawSprite(l_a->win, obstacle->sprite, NULL);
        obstacle = obstacle->next;
    }
    sfRenderWindow_drawSprite(l_a->win, l_a->list_enemy->end->sprite, NULL);
}

int *size_element(obs *obstacle, int nb_lines, int nb_cols)
{
    sfVector2u x = sfTexture_getSize(sfSprite_getTexture(obstacle->sprite));
    sfVector2f s_p = sfSprite_getScale(obstacle->sprite);
    int width = x.x / nb_cols * s_p.x;
    int length = x.y / nb_lines * s_p.y;
    int *size = malloc(sizeof(int) * 2);

    size[0] = width;
    size[1] = length;
    return (size);
}