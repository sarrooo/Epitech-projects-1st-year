/*
** EPITECH PROJECT, 2020
** my_hunter 
** File description:
** score of hunter
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <time.h>
#include "include/my.h"
#include "lib/my.h"
#include <stdio.h>

int score(sfSprite *p, sfRenderWindow *win, sfEvent event, int *b)
{
    sfMouseButtonEvent p_c = analyse_events(win, event);
    sfVector2u x = sfTexture_getSize(sfSprite_getTexture(p));
    int l_w = p_c.x * 1400 / sfRenderWindow_getSize(win).x;
    int l_l = p_c.y * 800 / sfRenderWindow_getSize(win).y;
    sfVector2f pS = sfSprite_getPosition(p);
    sfVector2f s_p = sfSprite_getScale(p);
    sfBool c = sfMouse_isButtonPressed(p_c.button);
    sfVector2u size = sfRenderWindow_getSize(win);

    if (l_w <= pS.x + (x.x / 3 * s_p.x) && p_c.x >= pS.x) {
        if (l_l <= pS.y + (x.y / 3 * s_p.y) && p_c.y >= pS.y) {
            b[1] = b[1] + 1;
            return (1);
        }
    }
    else if (c == sfTrue && p_c.y <= size.y && p_c.y > 0) {
        b[2] = b[2] + 1;
        return (0);
    }
    return (0);
}

char int_str(int nb, int base)
{
    if (nb < base && nb >= 0) {
        return (nb + 48);
    }
    if (base <= nb) {
        int_str(nb / base, base);
        int_str(nb % base, base);
    }
}

char *str_int(int nb)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 4);

    if (nb < 0)
        nb = nb * -1;
    while (nb >= 10) {
        str[i++] = int_str(nb % 10, 10);
        nb = nb / 10;
    }
    str[i++] = int_str(nb, 10);
    str[i] = 0;
    return (my_revstr(str));
}

char *str_cat(char *s1, char *s2)
{
    char *dest = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
    int i = 0;

    for (i = 0; i < my_strlen(s1); i++)
        dest[i] = s1[i];
    for (int z = 0; z < my_strlen(s2); z++)
        dest[i++] = s2[z];
    dest[i] = 0;
    return (dest);
}
