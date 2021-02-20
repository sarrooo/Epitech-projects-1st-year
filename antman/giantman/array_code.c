/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** manage array_code
*/

#include "include/my.h"

code_array *stock_code(code_array *stat_code, uncompress_info *str_info)
{
    int j = 1;
    int size_in_byte = 0;

    stat_code = malloc(sizeof(code_array) * (str_info->str[0] + 1));
    for (int i = 0; i < str_info->str[0]; i++) {
        stat_code[i].value = str_info->str[j++];
        stat_code[i].code_len = str_info->str[j++];
        stat_code[i].nb_cases = str_info->str[0];
        size_in_byte = stat_code[i].code_len / 8;
        if (stat_code[i].code_len % 8 != 0)
            size_in_byte = size_in_byte + 1;
        stat_code[i].size_in_byte = size_in_byte;
        if (size_in_byte > str_info->size_in_byte_max)
            str_info->size_in_byte_max = size_in_byte;
        stat_code[i].code = malloc(sizeof(unsigned char) * size_in_byte);
        for (int x = 0; x < size_in_byte; x++)
            stat_code[i].code[x] = str_info->str[j++];
    }
    str_info->str = str_info->str + j;
    str_info->str_len = str_info->str_len - j;
    return (stat_code);
}

void swap_code(int i, int w, code_array *stat_code)
{
    code_array temp;

    if (i != w) {
        temp = stat_code[i];
        stat_code[i] = stat_code[w];
        stat_code[w] = temp;
    }
}

int sort_stock_code(code_array *stat_code, int size)
{
    int x;
    int w = 0;

    if (size < 2)
        return (0);
    x = stat_code[size - 1].code_len;
    for (int i = 0; i < size; i++) {
        if (stat_code[i].code_len <= x) {
            swap_code(i, w, stat_code);
            w = w + 1;
        }
    }
    sort_stock_code(stat_code, w - 1);
    sort_stock_code(stat_code + w - 1, size - w + 1);
}