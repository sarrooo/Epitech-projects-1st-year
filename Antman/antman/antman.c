/*
** EPITECH PROJECT, 2021
** antman
** File description:
** compress file
*/

#include "include/my.h"

int main(int ac, char **av)
{
    uncompress_info *str_info;
    char_info *stat_freq;
    heap *tree;
    int *code = malloc(sizeof(int) * 256);

    if (code == NULL || ac != 3)
        return (84);
    str_info = set_struct_str(ac, av);
    if (str_info == NULL || error_handling(ac, av) == 1)
        return (84);
    if (str_info->nb_cases == 0 && my_strcmp(str_info->str, "\0") == 0) {
        return (0);
    }
    write(1, &str_info->str_len, 4);
    stat_freq = count_freq(str_info);
    tree = set_heap(tree, stat_freq, str_info->nb_cases);
    set_tree(tree, stat_freq, str_info->nb_cases);
    set_code(tree->array_node[0], 0, code, stat_freq);
    transmit_code(stat_freq, str_info);
    huff_compilation_str(av, stat_freq, str_info);
    return (0);
}