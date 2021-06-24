/*
** EPITECH PROJECT, 2021
** antman
** File description:
** mange heap 2/2
*/

#include "include/my.h"

void sort_heap(heap *heap_tree, int index)
{
    int nright = 2 * index + 2;
    int nleft = 2 * index + 1;
    int temp = index;
    int freq_index = heap_tree->array_node[index]->stat_freq.freq;
    heap_node **node_index = &heap_tree->array_node[index];

    if (nleft < heap_tree->size)
        if (heap_tree->array_node[nleft]->stat_freq.freq < freq_index)
            temp = nleft;
    freq_index = heap_tree->array_node[temp]->stat_freq.freq;
    if (nright < heap_tree->size)
        if (heap_tree->array_node[nright]->stat_freq.freq < freq_index)
            temp = nright;
    if (index != temp) {
        swap_heap_nodes(&heap_tree->array_node[temp], node_index);
        sort_heap(heap_tree, temp);
    }
}

heap *set_heap(heap *heap_tree, char_info *stat_freq, int nb_cases)
{
    heap_tree = create_heap(nb_cases);
    int j = 0;

    for (int i = 0; i < 256; i++) {
        if (stat_freq[i].freq != 0)
            heap_tree->array_node[j++] = create_heap_nodes(stat_freq[i]);
    }
    heap_tree->size = nb_cases - 1;
    for (int i = (heap_tree->size - 1) / 2; i >= 0; i--) {
        sort_heap(heap_tree, i);
    }
    return (heap_tree);
}

heap_node *get_head_value(heap *heap_tree)
{
    heap_node *first_value = malloc(sizeof(heap_node));

    first_value = heap_tree->array_node[0];
    heap_tree->size--;
    heap_tree->array_node[0] = heap_tree->array_node[heap_tree->size];
    sort_heap(heap_tree, 0);
    return (first_value);
}

int insert_heap_value(heap *heap_tree, heap_node *new)
{
    int index = heap_tree->size;
    int freq_parent = heap_tree->array_node[(index - 1) / 2]->stat_freq.freq;

    while (index && new->stat_freq.freq < freq_parent) {
        heap_tree->array_node[index] = heap_tree->array_node[(index - 1) / 2];
        index = (index - 1) / 2;
        freq_parent = heap_tree->array_node[(index - 1) / 2]->stat_freq.freq;
    }
    heap_tree->size = heap_tree->size + 1;
    heap_tree->array_node[index] = new;
    return (index);
}