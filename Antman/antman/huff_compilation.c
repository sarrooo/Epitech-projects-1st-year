/*
** EPITECH PROJECT, 2021
** antman
** File description:
** compilation
*/

#include "include/my.h"

int add_bit(int pos_bit, int idx, unsigned char *unpack_str)
{
    unsigned char temp = 1;

    temp = temp << (7 - pos_bit);
    unpack_str[idx] = unpack_str[idx] | temp;
    return (0);
}

int finish_huff_str(unsigned char *unpack_str, int j, int pos_bit)
{
    int len_unpack = 0;

    if (pos_bit == 0)
        len_unpack = j;
    else
        len_unpack = j + 1;
    write(1, unpack_str, len_unpack);
}

int *fill_bytes(char_info *s_f, uncompress_info *inf, char *un_s, huff_var *v)
{
    if (s_f[inf->str[v->i]].codes[v->x] != 0) {
        add_bit(v->pos_bit, v->j, un_s);
    }
    v->pos_bit++;
    if (v->pos_bit > 7) {
        v->pos_bit = 0;
        un_s[v->j + 1] = 0;
        v->j++;
    }
}

int huff_compilation_str(char **av, char_info *stat_freq, uncompress_info* inf)
{
    unsigned char *unpack_str = malloc(sizeof(char) * inf->str_len);
    int j = 0;
    int pos_bit = 0;
    huff_var *variable = malloc(sizeof(huff_var));

    variable->j = 0;
    variable->pos_bit = 0;
    variable->i = 0;
    unpack_str[0] = 0;
    for (variable->i; variable->i < inf->str_len; variable->i++) {
        for (int x = 0; x < stat_freq[inf->str[variable->i]].len_code; x++) {
            variable->x = x;
            fill_bytes(stat_freq, inf, unpack_str, variable);
        }
    }
    finish_huff_str(unpack_str, variable->j, variable->pos_bit);
}