/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** Manage code
*/

#include "include/my.h"

int set_code(unsigned char *temp, var_cmp *var, uncompress_info *str_info)
{
    int index_str = var[0].code_len / 8;
    unsigned char actual_bit;
    int offset = 8 - (var[0].code_len - (8 * (var[0].code_len / 8)));

    if (offset == 8)
        offset = 0;
    if (var[0].code_len % 8 != 0)
        index_str = index_str + 1;
    index_str = index_str - 1;
    actual_bit = str_info->str[var[0].i];
    actual_bit = actual_bit << var[0].pos_bit;
    actual_bit = actual_bit >> 7;
    actual_bit = actual_bit << offset;
    temp[index_str] = temp[index_str] | actual_bit;
    var[0].pos_bit++;
    if (var[0].pos_bit > 7) {
        var[0].pos_bit = 0;
        var[0].i++;
    }
    return (0);
}

int reset_var(var_cmp *var)
{
    var[0].ok = 0;
    var[0].index = 0;
    var[0].code_len = 0;
    return (0);
}

int unpack_str(code_array *stat_code, uncompress_info *str_info)
{
    int size_max = str_info->size_in_byte_max;
    unsigned char *temp = malloc(sizeof(unsigned char) * size_max);
    unsigned char *str = malloc(sizeof(unsigned char) * str_info->unpack_len);
    var_cmp *var = malloc(sizeof(var_cmp));
    int index_unpack = 0;

    var[0].pos_bit = 0;
    var[0].i = 0;
    while (index_unpack < str_info->unpack_len) {
        reset_var(var);
        temp = malloc(sizeof(unsigned char) * str_info->size_in_byte_max);
        for (int j = 0; j < str_info->size_in_byte_max; j++)
            temp[j] = 0;
        while (var[0].ok == 0) {
            var[0].code_len = var[0].code_len + 1;
            set_code(temp, var, str_info);
            cmp_code(temp, stat_code, var);
        }
        str[index_unpack++] = var[0].letter;
    }
    write(1, str, index_unpack);
}

int cmp_code_aux(code_array *code, unsigned char *temp, var_cmp *var, int i)
{
    for (int j = 0; j < code[i].size_in_byte; j++) {
        if (temp[j] != code[i].code[j]) {
            var[0].ok = 0;
            break;
        }
    }
}

int cmp_code(unsigned char *temp, code_array *code, var_cmp *var)
{
    int i = 0;

    for (i = var[0].index; code[i].code_len == var[0].code_len; i++) {
        var[0].ok = 1;
        cmp_code_aux(code, temp, var, i);
        if (var[0].ok == 1) {
            var[0].index = 0;
            var[0].letter = code[i].value;
            return (0);
        }
    }
    var[0].index = i;
    return (0);
}