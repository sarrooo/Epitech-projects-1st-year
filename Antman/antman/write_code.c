/*
** EPITECH PROJECT, 2021
** antman
** File description:
** write code for unpack
*/

#include "include/my.h"

void write_code(char_info *s_fq, unsigned char *code_str, int i, int len_bytes)
{
    int z = 0;
    int idx = 2;
    int pos_bit = 0;

    for (z = 0; z < s_fq[i].len_code; z++) {
        if (s_fq[i].codes[z] == 1)
            add_bit(pos_bit, idx, code_str);
        pos_bit++;
        if (pos_bit > 7 && z + 1 < s_fq[i].len_code) {
            pos_bit = 0;
            code_str[idx + 1] = 0;
            idx++;
        }
    }
    write(1, code_str, idx + 1);
}

int count_len_bytes(char_info *stat_freq, int i)
{
    int len_bytes = 0;

    if (stat_freq[i].len_code % 8 == 0)
        len_bytes = 2 + (stat_freq[i].len_code / 8);
    else
        len_bytes = 2 + (stat_freq[i].len_code / 8 + 1);
    return (len_bytes);
}

void transmit_code(char_info *stat_freq, uncompress_info *str_info)
{
    unsigned char *code_str;
    int len_bytes = 0;
    unsigned char nb_cases = str_info->nb_cases;

    write(1, &nb_cases, 1);
    for (int i = 0; i < 256; i++) {
        if (stat_freq[i].freq != 0) {
            len_bytes = count_len_bytes(stat_freq, i);
            code_str = malloc(sizeof(unsigned char) * len_bytes);
            code_str[0] = i;
            code_str[1] = stat_freq[i].len_code;
            code_str[2] = 0;
            write_code(stat_freq, code_str, i, len_bytes);
        }
    }
}