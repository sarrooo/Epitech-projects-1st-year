/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init point for map 1
*/

#include "include/defender.h"

point init_point(float x_max, float y_max, float vector_x, float vector_y)
{
    point point_map;

    point_map.max_point.x = x_max;
    point_map.max_point.y = y_max;
    point_map.move.x = vector_x;
    point_map.move.y = vector_y;
    return (point_map);
}