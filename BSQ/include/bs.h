/*
** EPITECH PROJECT, 2020
** bs.h
** File description:
** prototype of my_function
*/

#ifndef BS_H_

int my_getnbr(char const *str);

int my_put_nbr(int nb);

void my_putchar(char c);

int my_strlen(char const *str);

int my_putstr(char const *str);

int my_show_word_array(char * const *tab);

char **mem_alloc_2d_array(int nb_rows, int nb_cols);

char *load_file_in_mem(char const *filepath);

char *load_file(char const *filepath, int rows, int colums);

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols);

int is_square_of_size(char **map, int row, int col, int square_size);

int is_square_of_x(char **map, int row, int col, int square_size);

int find_biggest_square(char **map, int *n_rows, int row, int col);

char *mem_alloc(char const *a, char const *b);

char **mem_alloc_2d_array(int nb_rows, int nb_cols);

char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols);

int det_nb(int nb, int numbers);

int array_2d_how_many(int **arr, int nb_rows, int nb_cols, int number);

void array_1d_print_chars(char const *arr);

void array_1d_print_ints(int const *arr, int size);

int array_1d_sum(int const *arr, int size);

int array_2d_sum(int **arr, int nb_rows, int nb_cols);

int fs_open_file(char const *filepath);

void fs_understand_return_of_read(int fd, char *buffer, int size);

void fs_cat_500_bytes(char const *filepath);

void fs_cat_x_bytes(char const *filepath, int x);

void fs_print_first_line(char const *filepath);

int fs_get_number_from_first_line(char const *filepath);

int first_len(int len, char *buff, int x);

#endif /* BS_H_ */
