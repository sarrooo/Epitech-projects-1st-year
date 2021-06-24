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
    unsigned int str_len;
    unsigned char *str;
    unsigned char nb_cases;
}uncompress_info;

typedef struct char_info
{
    unsigned char value;
    int freq;
    int *codes;
    int len_code;
}char_info;

typedef struct heap_node
{
    char_info stat_freq;
    struct heap_node *nleft;
    struct heap_node *nright;
}heap_node;

typedef struct huff_var
{
    int x;
    int i;
    int j;
    int pos_bit;
}huff_var;

typedef struct heap
{
    int size;
    unsigned int capacity;
    struct heap_node **array_node;
}heap;

int error_handling(int ac, char **av);

unsigned char *read_files(int ac, char **av, uncompress_info *str_info);

char_info *count_freq(uncompress_info *str_info);

uncompress_info *set_struct_str(int ac, char **av);

heap_node *create_heap_nodes(char_info stat_freq);

heap *create_heap(unsigned int size);

void build_heap(heap *heap_tree);

heap *set_heap(heap *heap_tree, char_info *stat_freq, int nb_cases);

void swap_heap_nodes(heap_node **node_1, heap_node **node_2);

int insert_heap_value(heap *heap_tree, heap_node *node);

heap_node *get_head_value(heap *heap_tree);

void set_tree(heap *heap_tree, char_info *stat_freq, int nb_cases);

void sort_heap(heap *heap_tree, int index);

void set_code(heap_node *origin, int nb_node, int *code, char_info *stat_freq);

void print_code(char_info *stat_freq);

int add_bit(int pos_bit, int idx, unsigned char *unpack_str);

int finish_huff_str(unsigned char *unpack_str, int j, int pos_bit);

int *fill_bytes(char_info *s_fq, uncompress_info *f, char *u_s, huff_var *var);

int huff_compilation_str(char **av, char_info *sta_freq, uncompress_info* inf);

int count_len_bytes(char_info *stat_freq, int i);

void write_code(char_info *s_fq, unsigned char *code_str, int i, int len_bytes);

void transmit_code(char_info *stat_freq, uncompress_info *str_info);

#endif