/*
** EPITECH PROJECT, 2020
** check_history
** File description:
** example of bad code:
*/

#include "shell42.h"

char *get_begin(char *command, int i)
{
    char *res = malloc(sizeof(char) * i + 1);

    if (i == 0) {
        free(res);
        return ("\0");
    }
    for (int j = 0; j < i; j++) {
        res[j] = command[j];
    } return (res);
}

char *get_end(char *command, char *concat, int i)
{
    char *res = malloc(sizeof(char) * (strlen(concat) + i));
    int j = i;

    for (; command[j] != '!' && command[j] != '\0'; j++);
    j = 1   + j + strlen(concat);
    if (j == strlen(command))
        return ("\0");
    for (int x = 0; strlen(command) > j; j++, x++)
        res[x] = command[j];
    return (res);
}

char *concat_command(char *history, char *command, char *concat, int i) {
    char *begin = get_begin(command, i);
    char *end = get_end(command, concat, i);
    char *res;
    int x = 0;

    if (end == NULL && begin == NULL)
        return (history);
    else {
        res = malloc(sizeof(char) * ((strlen(begin)
                + strlen(end) + strlen(history))) + 1);
        for (; begin != NULL && begin[x] != '\0'; x++)
            res[x] = begin[x];
        for (int y = 0; strlen(history) > y; y++, x++)
            res[x] = history[y];
        for (int z = 0; end != NULL && strlen(end) > z; z++, x++)
            res[x] = end[z];
    } res[x] = '\0';
    return (res);

}

char *get_command_history(history_t *history, char *command, int i)
{
    char *str_hist = get_hist(command, i);
    char *res;

    if (history != NULL && history->next == NULL) {
        if (my_cmp(history->cmd, str_hist) == 0) {
            res = concat_command(history->cmd, command, str_hist, i);
            return (res);
        }
    }
    for (; history != NULL && history->next != NULL; history = history->next) {
        if (my_cmp(history->cmd, str_hist) == 0) {
            res = concat_command(history->cmd, command, str_hist, i);
            return (res);
        }
    }
    return (delete_point(command, i));
}

char *check_history(history_t **hist, char *command)
{
    for (int i = 0; command[i] != '\0'; i++) {
        if (command[i] == '!' && (i == 0 || command[i - 1] == ' '))
            command = get_command_history(*hist, command, i);
    }
    return (command);
}