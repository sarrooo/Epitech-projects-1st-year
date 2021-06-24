/*
** EPITECH PROJECT, 2020
** bs.h
** File description:
** prototype of my_function
*/

#ifndef MY_H_

#include "../lib/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct uncompress_info
{
    int str_len;
    unsigned char *str;
    unsigned int nb_cases;
    int size_in_byte_max;
    unsigned int unpack_len;
}uncompress_info;

typedef struct code_array
{
    int code_len;
    int nb_cases;
    int size_in_byte;
    unsigned char *code;
    unsigned char value;
}code_array;

typedef struct var_cmp
{
    int index;
    int ok;
    int code_len;
    int pos_bit;
    int i;
    unsigned char letter;
}var_cmp;

int error_handling(int ac, char **av);

unsigned char *read_files(int ac, char **av, uncompress_info *str_info);

uncompress_info *set_struct_str(int ac, char **av);

code_array *stock_code(code_array *stat_code, uncompress_info *str_info);

void swap_code(int i, int w, code_array *stat_code);

int sort_stock_code(code_array *stat_code, int size);

int set_code(unsigned char *temp, var_cmp *var, uncompress_info *str_info);

int unpack_str(code_array *stat_code, uncompress_info *str_info);

int reset_var(var_cmp *var);

int cmp_code(unsigned char *temp, code_array *code, var_cmp *var);

int cmp_code_aux(code_array *code, unsigned char *temp, var_cmp *var, int i);

#endif