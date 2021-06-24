/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** foreach_parsing
*/

#include "shell42.h"

char **malloc_2d_array(char *arr)
{
    char **str;
    int size = 0;
    int max = 0;
    int add = 0;

    for (int x = 0; arr[x] != '\0';) {
        for (; arr[x] != ' ' && arr[x] != '\0'; x++)
            add++;
        for (; arr[x] == ' '; x++);
        if (add > max)
            max = add;
        size++;
        add = 0;
    } str = malloc(sizeof(char *) * size + 1);
    for (int x = 0; x < size; x++)
        str[x] = malloc(sizeof(char) * max + 1);
    return (str);
}

char **str_to_2d(char *str)
{
    char **array = malloc_2d_array(str);
    char *word;
    int x;

    for (x = 0; str[x] != '\0'; x++)
        if (str[x] == '\t')
            str[x] = ' ';
    word = strtok(str, " ");
    for (x = 0; word != NULL; x++) {
        array[x] = word;
        word = strtok(NULL, " ");
    } array[x] = NULL;
    return (array);
}