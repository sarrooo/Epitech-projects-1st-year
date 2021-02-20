/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** detect
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

struct dirent *dot_files(struct dirent *dir_info, DIR *directory)
{
    while (dir_info->d_name[0] == 46) {
        dir_info = readdir(directory);
        if (dir_info == NULL)
            return (NULL);
    }
    return (dir_info);
}

int detect_error_ls(char **av, int *option, struct stat *info2, int i)
{
    if (option[5] == -1)
        av[option[5]] = "./";
    if (lstat(av[option[5]], info2) == -1 && option[5] > 0) {
        write(2, "Files not found\n", 16);
        exit(84);
    }
    if (det_ty_file(info2->st_mode) == 1)
        if (option[i] != 0 && opendir(av[option[i]]) == NULL) {
            write(2, "Permission denied\n", 18);
            exit(84);
        }
    return (0);
}

char *str_l(int x)
{
    char *str = malloc(sizeof(char) * 5);

    str[0] = '%';
    str[1] = x + 48;
    str[2] = 'd';
    str[3] = ' ';
    str[4] = 0;
    return (str);
}
