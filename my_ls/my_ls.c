/*
** EPITECH PROJECT, 2020
** My_ls
** File description:
** put information of files
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

int main_ls(char *path, int *option)
{
    struct stat *info = malloc(sizeof(struct stat));

    lstat(path, info);
    if (option[5] == 0 || option[5] == -1 || my_strcmp(path, ".") == 0)
        path = "./";
    else if (det_ty_file(info->st_mode) == 1)
        path = str_cat(path, "/");
    if (det_ty_file(info->st_mode) > 1 || option[2] == 1)
        print_files(path, option, info, 0);
    if (det_ty_file(info->st_mode) == 1 && option[2] != 1)
        print_dir(path, option);
    return (0);
}

int main(int ac, char **av)
{
    struct stat *info2 = malloc(sizeof(struct stat));
    int *option = malloc(sizeof(int) * 10);

    option = det_option(ac, av);
    for (int i = 5; option[i] > 0 || i == 5; i++) {
        detect_error_ls(av, option, info2, i);
        lstat(av[option[i]], info2);
        print_rec(option, info2, i, av[option[i]]);
        main_ls(av[option[i]], option);
    }
    if (det_ty_file(info2->st_mode) > 1 && option[0] != 1 && option[5] == -1)
        my_printf("\n");
    return (0);
}
