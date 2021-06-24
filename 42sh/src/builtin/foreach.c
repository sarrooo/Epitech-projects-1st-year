/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** foreach
*/

#include "shell42.h"

char *params(char **cmd)
{
    size_t size = BUFSIZ;
    char *buff = malloc(sizeof(char) * BUFSIZ);

    if (isatty(0))
        printf("foreach? ");
    if (getline(&buff, &size, stdin) == -1)
        return (NULL);
    buff[strlen(buff) - 1] = '\0';
    if (strcmp(buff, "end") == 0)
        return (NULL);
    return (buff);
}

char **get_args(char **cmd, int *nb_arg)
{
    int size = 0;
    int add = 0;
    char **nstr;

    for (; cmd[size] != NULL; size++);
    nstr = malloc(sizeof(char *) * size + 1);
    for (int x = 2; x < size; x++) {
        nstr[add] = malloc(sizeof(char) * strlen(cmd[x]) + 1);
        nstr[add++] = cmd[x];
    }
    *nb_arg = add;
    return (nstr);
}

char **get_buff(char **cmd, int *siz)
{
    int size = 0;
    char **tab = malloc(sizeof(char *) * 2);
    char *buff = params(cmd);

    while (buff != NULL) {
        tab[size] = malloc(sizeof(char) * strlen(buff) + 1);
        tab[size] = buff;
        buff = params(cmd);
        size++;
        tab = realloc(tab, sizeof(char *) * size + 1);
    }
    *siz = size;
    return (tab);
}

char **allocate(char **array)
{
    for (int x = 0; array[x] != NULL; x++) {
        array[x] = strdup(array[x]);
    }
    return (array);
}

void builtin_foreach(head_t *head, char **cmd)
{
    int size = 0;
    int nb_args = 0;
    char **path;
    char **tab;
    char **args = get_args(cmd, &nb_args);
    cmd_list_t *cmd_l = head->cmd_list;

    tab = get_buff(cmd, &size);
    for (int x = 0; x < nb_args; x++) {
        for (int y = 0; y < size; y++) {
            path = str_to_2d(strdup(tab[y]));
            if (cmd_l->next == NULL)
                cmd_l = new_element(cmd_l, allocate(path));
            else {
                cmd_l = cmd_l->next;
                cmd_l = insert_element(cmd_l, allocate(path));
            }
        }
    }
}