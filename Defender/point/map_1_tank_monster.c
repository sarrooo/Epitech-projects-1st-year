/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init point for map 1 for tank monster
*/

#include "include/defender.h"

void init_point_map1_tank_3(point *point_map, float speed)
{
    point_map[40] = init_point(625, 360, 0, speed);
    point_map[41] = init_point(595, 360, speed * -1, 0);
    point_map[42] = init_point(595, 400, 0, speed);
    point_map[43] = init_point(540, 400, speed * -1, 0);
    point_map[44] = init_point(540, 420, 0, speed);
    point_map[45] = init_point(450, 420, speed * -1, 0);
    point_map[46] = init_point(450, 455, 0, speed);
    point_map[47] = init_point(375, 455, speed * -1, 0);
    point_map[48] = init_point(375, 490, 0, speed);
    point_map[49] = init_point(320, 490, speed * -1, 0);
    point_map[50] = init_point(320, 490, 0, speed);
    point_map[51] = init_point(270, 490, speed * -1, 0);
    point_map[52] = init_point(270, 620, 0, speed);
    point_map[53] = init_point(250, 620, speed * -1, 0);
    point_map[54] = init_point(250, 670, 0, speed);
    point_map[55] = init_point(210, 670, speed * -1, 0);
    point_map[56] = init_point(210, 700, 0, speed);
    point_map[57] = init_point(160, 700, speed * -1, 0);
    point_map[58] = init_point(160, 730, 0, speed);
    point_map[59] = init_point(-140, 730, speed * -1, 0);
}

void init_point_map1_tank_2(point *point_map, float speed)
{
    point_map[19] = init_point(1625, 400, speed, 0);
    point_map[20] = init_point(1625, 370, 0, speed * -1);
    point_map[21] = init_point(1660, 370, speed, 0);
    point_map[22] = init_point(1660, 320, 0, speed * -1);
    point_map[23] = init_point(1710, 320, speed, 0);
    point_map[24] = init_point(1710, 140, 0, speed * -1);
    point_map[25] = init_point(1680, 140, speed * -1, 0);
    point_map[26] = init_point(1680, 105, 0, speed * -1);
    point_map[27] = init_point(1645, 105, speed * -1, 0);
    point_map[28] = init_point(1645, 85, 0, speed * -1);
    point_map[29] = init_point(1585, 85, speed * -1, 0);
    point_map[30] = init_point(1585, 85, 0, speed * -1);
    point_map[31] = init_point(780, 85, speed * -1, 0);
    point_map[32] = init_point(780, 110, 0, speed);
    point_map[33] = init_point(710, 110, speed * -1, 0);
    point_map[34] = init_point(710, 150, 0, speed);
    point_map[35] = init_point(670, 150, speed * -1, 0);
    point_map[36] = init_point(670, 255, 0, speed);
    point_map[37] = init_point(650, 255, speed * -1, 0);
    point_map[38] = init_point(650, 310, 0, speed);
    point_map[39] = init_point(625, 310, speed * -1, 0);
}

void init_point_map1_tank_4(point *point_map, float speed)
{
    point_map[15] = init_point(1410, 580, speed, 0);
    point_map[16] = init_point(1410, 430, 0, speed * -1);
    point_map[17] = init_point(1480, 430, speed, 0);
    point_map[18] = init_point(1480, 400, 0, speed * -1);
}

point *init_point_map1_tank(int nb_points, float speed)
{
    point *point_map = malloc(sizeof(point) * nb_points);

    point_map[0] = init_point(1720, 850, 0, speed * -1);
    point_map[1] = init_point(1700, 850, speed * -1, 0);
    point_map[2] = init_point(1700, 820, 0, speed * -1);
    point_map[3] = init_point(1685, 820, speed * -1, 0);
    point_map[4] = init_point(1685, 790, 0, speed * -1);
    point_map[5] = init_point(1665, 790, speed * -1, 0);
    point_map[6] = init_point(1665, 760, 0, speed * -1);
    point_map[7] = init_point(1540, 760, speed * -1, 0);
    point_map[8] = init_point(1540, 730, 0, speed * -1);
    point_map[9] = init_point(1445, 730, speed * -1, 0);
    point_map[10] = init_point(1445, 700, 0, speed * -1);
    point_map[11] = init_point(1425, 700, speed * -1, 0);
    point_map[12] = init_point(1425, 660, 0, speed * -1);
    point_map[13] = init_point(1385, 660, speed * -1, 0);
    point_map[14] = init_point(1385, 580, 0, speed * -1);
    init_point_map1_tank_4(point_map, speed);
    init_point_map1_tank_2(point_map, speed);
    init_point_map1_tank_3(point_map, speed);
    return (point_map);
}