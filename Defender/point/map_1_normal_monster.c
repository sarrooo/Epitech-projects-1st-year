/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init point for map 1 for normal monster
*/

#include "include/defender.h"

void init_point_map1_normal_2(point *point_map, float speed)
{
    point_map[15] = init_point(640, 210, speed * -1, 0);
    point_map[16] = init_point(640, 370, 0, speed);
    point_map[17] = init_point(600, 370, speed * -1, 0);
    point_map[18] = init_point(600, 430, 0, speed);
    point_map[19] = init_point(430, 430, speed * -1, 0);
    point_map[20] = init_point(430, 480, 0, speed);
    point_map[21] = init_point(330, 480, speed * -1, 0);
    point_map[22] = init_point(330, 720, 0, speed);
    point_map[23] = init_point(250, 720, speed * -1, 0);
    point_map[24] = init_point(250, 780, 0, speed);
    point_map[25] = init_point(-100, 780, speed * -1, 0);
}

point *init_point_map1_normal(int nb_points, float speed)
{
    point *point_map = malloc(sizeof(point) * nb_points);

    point_map[0] = init_point(1720, 850, 0, speed * -1);
    point_map[1] = init_point(1700, 850, speed * -1, 0);
    point_map[2] = init_point(1700, 780, 0, speed * -1);
    point_map[3] = init_point(1500, 780, speed * -1, 0);
    point_map[4] = init_point(1500, 720, 0, speed * -1);
    point_map[5] = init_point(1450, 720, speed * -1, 0);
    point_map[6] = init_point(1450, 490, 0, speed * -1);
    point_map[7] = init_point(1530, 490, speed * -1, 0);
    point_map[8] = init_point(1530, 440, 0, speed * -1);
    point_map[9] = init_point(1735, 440, speed, 0);
    point_map[10] = init_point(1730, 150, 0, speed * -1);
    point_map[11] = init_point(1680, 150, speed * -1, 0);
    point_map[12] = init_point(1680, 120, 0, speed * -1);
    point_map[13] = init_point(700, 120, speed * -1, 0);
    point_map[14] = init_point(700, 210, 0, speed);
    init_point_map1_normal_2(point_map, speed);
    return (point_map);
}