/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** manage paralax
*/

#include "include/my.h"

object *create_back(char *path, float offset)
{
    object *obj = malloc(sizeof(object));
    sfVector2f size;

    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(path, NULL);
    obj->rect = rect_sprite(1920, 1080);
    obj->move.x = offset;
    obj->move.y = 0;
    size.x = 0.41666667;
    size.y = 0.55555556;
    sfTexture_setSmooth(obj->texture, sfTrue);
    sfSprite_setScale(obj->sprite, size);
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    return (obj);
}

object *create_back_2(char *path, float offset)
{
    object *obj = malloc(sizeof(object));
    sfVector2f size;
    sfVector2f pos;

    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(path, NULL);
    obj->rect = rect_sprite(1920, 1080);
    obj->move.x = offset;
    obj->move.y = 0;
    size.x = 0.41666667;
    size.y = 0.55555556;
    pos.x = 799;
    pos.y = 0;
    sfSprite_setPosition(obj->sprite, pos);
    sfTexture_setSmooth(obj->texture, sfTrue);
    sfSprite_setScale(obj->sprite, size);
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    return (obj);
}

paralax *create_par(void)
{
    paralax *par = malloc(sizeof(paralax));

    par->b_6 = create_back("paralax/par_6.png", -1.3);
    par->b_6_2 = create_back_2("paralax/par_6.png", -1.3);
    par->b_5 = create_back("paralax/par_5.png", -1.3);
    par->b_5_2 = create_back_2("paralax/par_5.png", -1.3);
    par->b_4 = create_back("paralax/par_4.png", -1.6);
    par->b_4_2 = create_back_2("paralax/par_4.png", -1.6);
    par->b_3 = create_back("paralax/par_3.png", -1.9);
    par->b_3_2 = create_back_2("paralax/par_3.png", -1.9);
    par->b_2 = create_back("paralax/par_2.png", -4);
    par->b_2_2 = create_back_2("paralax/par_2.png", -4);
    par->b_1 = create_back("paralax/par_1.png", -8);
    par->b_1_2 = create_back_2("paralax/par_1.png", -8);
    return (par);
}

void draw_par(sfRenderWindow *win, paralax *par)
{
    sfRenderWindow_drawSprite(win, par->b_6->sprite, NULL);
    sfRenderWindow_drawSprite(win, par->b_6_2->sprite, NULL);
    sfRenderWindow_drawSprite(win, par->b_5->sprite, NULL);
    sfRenderWindow_drawSprite(win, par->b_5_2->sprite, NULL);
    sfRenderWindow_drawSprite(win, par->b_4->sprite, NULL);
    sfRenderWindow_drawSprite(win, par->b_4_2->sprite, NULL);
    sfRenderWindow_drawSprite(win, par->b_3->sprite, NULL);
    sfRenderWindow_drawSprite(win, par->b_3_2->sprite, NULL);
    sfRenderWindow_drawSprite(win, par->b_2->sprite, NULL);
    sfRenderWindow_drawSprite(win, par->b_2_2->sprite, NULL);
    sfRenderWindow_drawSprite(win, par->b_1->sprite, NULL);
    sfRenderWindow_drawSprite(win, par->b_1_2->sprite, NULL);
}

void move_all_par(sfRenderWindow *win, paralax *par)
{
    move_par(win, par->b_5);
    move_par(win, par->b_5_2);
    move_par(win, par->b_4);
    move_par(win, par->b_4_2);
    move_par(win, par->b_3);
    move_par(win, par->b_3_2);
    move_par(win, par->b_2);
    move_par(win, par->b_2_2);
    move_par(win, par->b_1);
    move_par(win, par->b_1_2);
}