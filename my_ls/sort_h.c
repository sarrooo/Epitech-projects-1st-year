/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** sort by hours
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

void info_1(char *path, char **all_files, int j, struct stat *info)
{
    if (my_strcmp(path, all_files[j]) != 0)
        lstat(str_cat(path, all_files[j]), info);
    else
        lstat(all_files[j], info);
}

void info_2(char *path, char **all_files, int j, struct stat *info)
{
    if (my_strcmp(path, all_files[j + 1]) != 0)
        lstat(str_cat(path, all_files[j + 1]), info);
    else
        lstat(all_files[j + 1], info);
}

int sort_h(char **all_files, char *path)
{
    char *temp;
    int ok = 0;
    int nb_files = count_nb_files(path);
    struct stat *info = malloc(sizeof(struct stat));
    struct stat *info1 = malloc(sizeof(struct stat));

    for (int i = 0; i < nb_files - 1; i++) {
        info_1(path, all_files, i, info);
        info_2(path, all_files, i, info1);
        if (info->st_mtime < info1->st_mtime) {
            temp = all_files[i + 1];
            all_files[i + 1] = all_files[i];
            all_files[i] = temp;
            ok = 1;
        }
    }
    return (ok);
}

int sort_h2(char **all_files, char *path)
{
    char *temp;
    int ok = 0;
    int nb_files = count_nb_files(path);
    struct stat *info = malloc(sizeof(struct stat));
    struct stat *info1 = malloc(sizeof(struct stat));

    for (int i = 0; i < nb_files - 1; i++) {
        info_1(path, all_files, i, info);
        info_2(path, all_files, i, info1);
        if (info->st_mtime > info1->st_mtime) {
            temp = all_files[i + 1];
            all_files[i + 1] = all_files[i];
            all_files[i] = temp;
            ok = 1;
        }
    }
    return (ok);
}

char **sort_hour(char *path, int *option)
{
    char **all_files = store_path(path);
    char **all_file2 = store_path(path);
    int nb_files = count_nb_files(path);
    int ok = 1;

    while (ok != 0) {
        if (option[3] != 1)
            ok = sort_h(all_files, path);
        if (option[3] == 1)
            ok = sort_h2(all_files, path);
    }
    return (all_files);
}
