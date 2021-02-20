/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** prototype of function
*/

#ifndef MY_H_

char *perm(mode_t perm_info);

int print_option(int *option, struct stat *info, int x);

int manage_option(struct dirent *dir_in, int *opt, struct stat *inf, char *la);

char *str_cat(char *s1, char *s2);

int det_ty_file(mode_t mode);

char type_fil(mode_t mode);

int *detect_option(char *av, int *option);

int *det_option(int ac, char **av);

char *str_int(int nb);

int det_max_size(char *path);

int total_ls_l(char *path, int *option);

struct dirent *dot_files(struct dirent *dir_info, DIR *directory);

int print_files(char *path, int *option, struct stat *info, int x);

void print_dir(char *path, int *option);

int print_rec(int *option, struct stat *info, int i, char *path);

int count_nb_files(char *path);

char **store_path(char *path);

char *my_strlowcase(char const *s1);

int my_strcmp_ls(char const *s1, char const *s2);

char **sort(char **all_files, char *path, int x);

char **sort2(char **all_files, char *path, int x);

char **sort_path(char *path, int *option);

int sort_h(char **all_files, char *path);

int sort_h2(char **all_files, char *path);

char **sort_hour(char *path, int *option);

char **sort_main(char *path, int *option);

int detect_error_ls(char **av, int *option, struct stat *info2, int i);

char *str_l(int x);

#endif /*MY_H_*/
