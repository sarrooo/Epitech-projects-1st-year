/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** sort 2
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "lib/my.h"
#include "include/my.h"

char **sort(char **all_files, char *path, int x)
{
    int nb_files = count_nb_files(path);
    char *char_temp;

    for (int i = 0; i < nb_files; i++)
        if (my_strcmp_ls(all_files[x], all_files[i]) > 0) {
            char_temp = all_files[x];
            all_files[x] = all_files[i];
            all_files[i] = char_temp;
        }
    return (all_files);
}

char **sort2(char **all_files, char *path, int x)
{
    int nb_files = count_nb_files(path);
    char *char_temp;

    for (int i = 0; i < nb_files; i++)
        if (my_strcmp_ls(all_files[x], all_files[i]) < 0) {
            char_temp = all_files[x];
            all_files[x] = all_files[i];
            all_files[i] = char_temp;
        }
    return (all_files);
}

char **sort_path(char *path, int *option)
{
    char **all_files = store_path(path);
    int nb_files = count_nb_files(path);

    for (int x = 0; x < nb_files; x++) {
        if (option[3] != 1)
            sort(all_files, path, x);
        if (option[3] == 1)
            sort2(all_files, path, x);
    }
    return (all_files);
}

char **sort_main(char *path, int *option)
{
    if (option[4] == 1)
        return (sort_hour(path, option));
    return (sort_path(path, option));
}
