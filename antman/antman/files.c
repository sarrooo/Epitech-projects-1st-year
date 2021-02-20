/*
** EPITECH PROJECT, 2021
** antman
** File description:
** manage files's info
*/

#include "include/my.h"


unsigned char *error(char **av, int fd, struct stat *info)
{
    if (info == NULL || fd == -1 || stat(av[1], info) == -1) {
        close(fd);
        return (NULL);
    }
    if (S_ISDIR(info->st_mode)) {
        close(fd);
        return (NULL);
    }
    return ("1");
}

unsigned char *read_files(int ac, char **av, uncompress_info *str_info)
{
    unsigned char *str;
    int fd = open(av[1], O_RDONLY);
    struct stat *info = malloc(sizeof(struct stat));

    if (error(av, fd, info) == NULL)
        return (NULL);
    if (info->st_size == 0) {
        close(fd);
        return ("\0");
    }
    str = malloc(sizeof(unsigned char) * (info->st_size + 1));
    if (str == NULL || read(fd, str, (int)info->st_size) == -1) {
        close(fd);
        return (NULL);
    }
    str[(int)info->st_size] = 0;
    str_info->str_len = (int)info->st_size;
    close(fd);
    return (str);
}

uncompress_info *set_struct_str(int ac, char **av)
{
    uncompress_info *str_info = malloc(sizeof(uncompress_info));

    if (str_info == NULL)
        return (NULL);
    str_info->str = read_files(ac, av, str_info);
    if (str_info->str == NULL)
        return (NULL);
    if (my_strcmp(str_info->str, "\0") == 0) {
        str_info->nb_cases = 0;
        return (str_info);
    }
    return (str_info);
}

int error_handling(int ac, char **av)
{
    int i = 0;

    if (my_strcmp(av[2], "1") != 0)
        i = 1;
    else
        return (0);
    if (my_strcmp(av[2], "2") != 0)
        i = 1;
    else
        return (0);
    if (my_strcmp(av[2], "3") != 0)
        i = 1;
    else
        return (0);
    return (i);
}