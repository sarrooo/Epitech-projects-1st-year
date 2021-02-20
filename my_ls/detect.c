/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** detect.c
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

int det_ty_file(mode_t mode)
{
    if (!(mode))
        return 0;
    if (S_ISDIR(mode))
        return (1);
    if (S_ISREG(mode))
        return (2);
    if (S_ISBLK(mode))
        return (3);
    if (S_ISCHR(mode))
        return (4);
    if (S_ISLNK(mode))
        return (5);
    if (S_ISFIFO(mode))
        return (6);
    if (S_ISSOCK(mode))
        return (7);
    return (0);
}

char type_fil(mode_t mode)
{
    if (S_ISDIR(mode))
        return ('d');
    if (S_ISREG(mode))
        return ('-');
    if (S_ISBLK(mode))
        return ('b');
    if (S_ISCHR(mode))
        return ('c');
    if (S_ISLNK(mode))
        return ('l');
    if (S_ISFIFO(mode))
        return ('p');
    if (S_ISSOCK(mode))
        return ('s');
    return (0);
}

int *detect_option(char *av, int *option)
{
    for (int i = 0; av[i] != 0; i++) {
        if (av[i] == 'l')
            option[0] = 1;
        if (av[i] == 'R')
            option[1] = 1;
        if (av[i] == 'd')
            option[2] = 1;
        if (av[i] == 'r')
            option[3] = 1;
        if (av[i] == 't')
            option[4] = 1;
    }
    return (option);
}

int *det_option(int ac, char **av)
{
    int *option = malloc(sizeof(int) * 10);
    int x = 5;

    option[0] = 0;
    option[1] = 0;
    option[2] = 0;
    option[3] = 0;
    option[4] = 0;
    option[5] = 0;
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-')
            detect_option(av[i], option);
        if (av[i][0] != '-')
            option[x++] = i;
    }
    if (x == 5)
        option[x + 1] = -1;
    else
        option[x] = -1;
    return (option);
}

int det_max_size(char *path)
{
    struct dirent *dir_info = malloc(sizeof(struct dirent));
    DIR *directory = opendir(path);
    struct stat *info = malloc(sizeof(struct stat));
    int size_temp = 0;

    dir_info = readdir(directory);
    size_temp = 0;
    while (dir_info) {
        dir_info = dot_files(dir_info, directory);
        if (dir_info == NULL)
            return (my_strlen(str_int(size_temp)));
        lstat(str_cat(path, dir_info->d_name), info);
        if (size_temp < info->st_size)
            size_temp = info->st_size;
        dir_info = readdir(directory);
    }
    closedir(directory);
    return (my_strlen(str_int(size_temp)));
}
