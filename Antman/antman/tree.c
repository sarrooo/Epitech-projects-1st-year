/*
** EPITECH PROJECT, 2021
** antman
** File description:
** manage huffman tree
*/

#include "include/my.h"

void set_tree(heap *heap_tree, char_info *stat_freq, int nb_cases)
{
    heap_node *nleft;
    heap_node *nright;
    heap_node *fusion = malloc(sizeof(heap_node));
    int freq_left = 0;
    int freq_right = 0;
    int j = 0;

    heap_tree->size++;
    while (heap_tree->size != 1) {
        nright = get_head_value(heap_tree);
        nleft = get_head_value(heap_tree);
        freq_left = nleft->stat_freq.freq;
        freq_right = nright->stat_freq.freq;
        fusion->stat_freq.freq = freq_right + freq_left;
        fusion->stat_freq.value = '\0';
        fusion->nleft = nleft;
        fusion->nright = nright;
        j = insert_heap_value(heap_tree, fusion);
        fusion = malloc(sizeof(heap_node));
    }
}

void print_code_aux(char_info *stat_freq, int i)
{
    my_printf("value->%c => ", stat_freq[i].value);
    for (int j = 0; j < stat_freq[i].len_code; j++) {
        my_printf("%d", stat_freq[i].codes[j]);
    }
    my_printf("\n");
}

void print_code(char_info *stat_freq)
{
    for (int i = 0; i < 256; i++) {
        if (stat_freq[i].freq != 0) {
            print_code_aux(stat_freq, i);
        }
    }
}

void set_code(heap_node *origin, int pos, int *code, char_info *stat_freq)
{
    if (origin->nleft != NULL) {
        code[pos] = 1;
        set_code(origin->nleft, pos + 1, code, stat_freq);
    }
    if (origin->nright != NULL) {
        code[pos] = 0;
        set_code(origin->nright, pos + 1, code, stat_freq);
    }
    if (origin->nleft == NULL && origin->nright == NULL) {
        stat_freq[origin->stat_freq.value].codes = malloc(sizeof(int) * pos);
        stat_freq[origin->stat_freq.value].len_code = pos;
        for (int j = 0; j < pos; j++)
            stat_freq[origin->stat_freq.value].codes[j] = code[j];
    }
}