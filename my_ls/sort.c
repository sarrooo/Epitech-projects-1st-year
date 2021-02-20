/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** sort
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

int count_nb_files(char *path)
{
    struct dirent *dir_info = malloc(sizeof(struct dirent));
    DIR *directory = opendir(path);
    int x = 0;

    dir_info = readdir(directory);
    while (dir_info) {
        dir_info = dot_files(dir_info, directory);
        if (dir_info == NULL)
            break;
        x++;
        dir_info = readdir(directory);
    }
    closedir(directory);
    return (x);
}

char **store_path(char *path)
{
    struct dirent *dir_info = malloc(sizeof(struct dirent));
    DIR *directory = opendir(path);
    int nb_files = count_nb_files(path);
    char **all_path = malloc(sizeof(char *) * (nb_files + 2));
    int i = 0;

    dir_info = readdir(directory);
    for (i = 0; dir_info; i++) {
        dir_info = dot_files(dir_info, directory);
        if (dir_info == NULL)
            break;
        all_path[i] = dir_info->d_name;
        dir_info = readdir(directory);
    }
    all_path[i] = 0;
    return (all_path);
}

char *my_strlowcase(char const *s1)
{
    char *str = malloc(sizeof(char) * my_strlen(s1) + 1);
    int max = my_strlen(s1);
    int x = 0;

    for (x = 0; s1[x] != 0; x++)
        str[x] = s1[x];
    str[x] = 0;
    for (int i = 0; i < max; i++) {
        if (65 <= str[i] && str[i] <= 90) {
            str[i] = str[i] + 32;
        }
    }
    return (str);
}

int my_strcmp_ls(char const *s1, char const *s2)
{
    int result;
    char *s1_b = my_strlowcase(s1);
    char *s2_b = my_strlowcase(s2);

    for (int i = 0; s1_b[i] != '\0' && s2_b[i] != '\0'; i++) {
        if (s1_b[i] == '.')
            i++;
        if (s2_b[i] == '.')
            i++;
        if (s1_b[i] != s2_b[i]) {
            result = s2_b[i] - s1_b[i];
            return (result);
        }
    }
    return (0);
}
