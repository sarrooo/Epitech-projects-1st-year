/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** Increase difficult
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <time.h>
#include "lib/my.h"
#include "include/my.h"
#include <stdio.h>

int *speed_parrot(int score)
{
    int *flow = malloc(sizeof(int) * 1);

    flow[0] = 15;
    if (score >= 5)
        flow[0] = 30;
    if (score >= 10)
        flow[0] = 35;
    if (score >= 15)
        flow[0] = 40;
    if (score >= 20)
        flow[0] = 44;
    if (score >= 25)
        flow[0] = 47;
    if (score >= 30)
        flow[0] = 50;
    if (score >= 35)
        flow[0] = 51;
    if (score >= 40)
        flow[0] = 53;
    return (flow);
}
