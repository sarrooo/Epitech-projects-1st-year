/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** print ls
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

int print_files(char *path, int *option, struct stat *info, int x)
{
    print_option(option, info, x);
    my_printf("%s", path);
    if (option[0] == 1)
        my_printf("\n");
    return (0);
}

void print_dir(char *path, int *option)
{
    int max_size = det_max_size(path);
    char **all_files = sort_main(path, option);
    int nb_files = count_nb_files(path);
    struct dirent *dir_info = malloc(sizeof(struct dirent));
    struct stat *info = malloc(sizeof(struct stat));

    if (option[0] == 1)
        my_printf("total %d\n", total_ls_l(path, option));
    for (int i = 0; i < nb_files; i++) {
        lstat(str_cat(path, all_files[i]), info);
        print_files(all_files[i], option, info, max_size);
        if (i < nb_files - 1 && option[0] != 1)
            my_printf(" ");
    }
    if (option[0] != 1)
        my_printf("\n");
}

int print_rec(int *opt, struct stat *info, int i, char *path)
{
    if (i > 5 && det_ty_file(info->st_mode) > 1 && opt[i] != -1) {
        if (opt[0] == 1)
            return 0;
        my_printf(" ");
        return 0;
    }
    if (opt[2] == 1) {
        if (i != 5)
            my_printf("  ");
        return 0;
    }
    if (i == 5 && opt[i + 1] != -1 && det_ty_file(info->st_mode) == 1)
        my_printf("%s:\n", path);
    else if (opt[i + 1] != -1 && det_ty_file(info->st_mode) == 1)
        my_printf("\n\n%s:\n", path);
    if (i != 5 && opt[i + 1] == -1 && det_ty_file(info->st_mode) == 1)
        my_printf("\n%s:\n", path);
    if (i != 5 && opt[i + 1] == -1 && det_ty_file(info->st_mode) > 1)
        my_printf("\n");
    return (0);
}
