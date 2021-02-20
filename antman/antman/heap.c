/*
** EPITECH PROJECT, 2021
** antman
** File description:
** manage heap
*/

#include "include/my.h"

char_info *count_freq(uncompress_info *str_info)
{
    char_info *stat_freq = malloc(sizeof(char_info) * 256);
    int nb_cases = 0;
    int j = 0;

    for (int i = 0; i < 256; i++) {
        stat_freq[i].freq = 0;
        stat_freq[i].value = i;
    }
    for (int i = 0; i < str_info->str_len; i++) {
        if (stat_freq[str_info->str[i]].freq == 0)
            nb_cases = nb_cases + 1;
        stat_freq[str_info->str[i]].freq++;
    }
    str_info->nb_cases = nb_cases;
    return (stat_freq);
}

heap_node *create_heap_nodes(char_info stat_freq)
{
    heap_node *node = malloc(sizeof(heap_node));

    node->stat_freq = stat_freq;
    node->nleft = NULL;
    node->nright = NULL;
    return (node);
}

heap *create_heap(unsigned int size)
{
    heap *heap_created = malloc(sizeof(heap));

    heap_created->capacity = size;
    heap_created->size = 0;
    heap_created->array_node = malloc(sizeof(heap_node *) * size);
    return (heap_created);
}

void swap_heap_nodes(heap_node **node_1, heap_node **node_2)
{
    heap_node *temp = malloc(sizeof(heap_node));

    temp = *node_1;
    *node_1 = *node_2;
    *node_2 = temp;
}