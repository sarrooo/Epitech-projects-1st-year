/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** decompress file
*/

#include "include/my.h"

int main(int ac, char **av)
{
    uncompress_info *str_info;
    code_array *stat_code;

    if (ac != 3)
        return (84);
    str_info = set_struct_str(ac, av);
    if (str_info == NULL || error_handling(ac, av) == 1)
        return (84);
    if (str_info->nb_cases == 0 && my_strcmp(str_info->str, "\0") == 0) {
        return (0);
    }
    str_info->size_in_byte_max = 0;
    stat_code = stock_code(stat_code, str_info);
    sort_stock_code(stat_code, stat_code[0].nb_cases);
    unpack_str(stat_code, str_info);
    return (0);
}