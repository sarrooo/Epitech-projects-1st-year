/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** option.c
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

char *perm(mode_t perm_info)
{
    char *dest = malloc(sizeof(char) * 10);
    char str[9] = "rwxrwxrwx";
    size_t j = 0;

    for (j; j < 9; j++) {
        if (perm_info & 1 << (8 - j))
            dest[j] = str[j];
        else
            dest[j] = '-';
    }
    dest[9] = '\0';
    return (dest);
}

int print_option(int *option, struct stat *info, int x)
{
    char *str = str_l(x);

    if (option[0] == 1) {
        my_printf("%c%s ", type_fil(info->st_mode), perm(info->st_mode));
        my_printf("%d ", info->st_nlink);
        my_printf("%s ", getpwuid(info->st_uid)->pw_name);
        my_printf("%s ", getgrgid(info->st_gid)->gr_name);
        my_printf("%d ", info->st_size);
        my_printf("%.12s ", ctime(&info->st_mtime) + 4);
    }
    return (0);
}

char *str_cat(char *s1, char *s2)
{
    char *dest = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
    int i = 0;

    for (i = 0; i < my_strlen(s1); i++)
        dest[i] = s1[i];
    for (int z = 0; z < my_strlen(s2); z++)
        dest[i++] = s2[z];
    dest[i] = 0;
    return (dest);
}

int total_ls_l(char *path, int *option)
{
    struct dirent *dir_info = malloc(sizeof(struct dirent));
    DIR *directory = opendir(path);
    struct stat *info = malloc(sizeof(struct stat));
    int total = 0;

    dir_info = readdir(directory);
    while (dir_info != NULL) {
        dir_info = dot_files(dir_info, directory);
        if (dir_info == NULL)
            return (total);
        lstat(str_cat(path, dir_info->d_name), info);
        total = total + (info->st_blocks / 2);
        dir_info = readdir(directory);
    }
    closedir(directory);
    free(info);
    return (total);
}

int manage_option(struct dirent *dir_inf, int *opt, struct stat *info, char *p)
{
    int max = det_max_size(p);
    int total = total_ls_l(p, opt);

    if (opt[0] == 1) {
        lstat(str_cat(p, dir_inf->d_name), info);
        print_option(opt, info, max);
        my_printf("%s", dir_inf->d_name);
        my_printf("\n");
        return (1);
    }
    return 0;
}
