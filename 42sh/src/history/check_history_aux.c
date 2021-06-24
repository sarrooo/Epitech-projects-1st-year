/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** check_history_aux
*/

#include "shell42.h"

char *get_hist(char *str, int i)
{
    char *res;
    int j = i + 1;
    int x = 0;

    for (; str[i] != '\0' && str[i] != ' '; i++);
    res = malloc(sizeof(char) * i);
    for (; j < i; j++, x++) {
        res[x] = str[j];
    } res[x] = '\0';
    return (res);
}

int my_cmp(char *stra, char *strb)
{
    int i = 0;
    int good = 0;

    for (; stra[i] != '\0' && strlen(strb) > i && good == 0; i++) {
        if (stra[i] != strb[i])
            good = 1;
    }
    if (good == 1)
        return 1;
    return 0;
}

char *delete_point(char *command, int i)
{
    char *str = get_hist(command, i);

    printf("%s: Event not found.\n", str);
    return ("\0");
}