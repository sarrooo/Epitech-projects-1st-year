/*
** EPITECH PROJECT, 2020
** Read_files
** File description:
** read in files with read()
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c);

int my_putstr(char const *str);

int my_getnbr(char const *str);

int fs_open_file(char const *filepath)
{
    int f_desc = 0;

    f_desc = open(filepath, O_RDONLY);
    if (f_desc < 0)
        return (84);
    return (f_desc);
}

void fs_understand_return_of_read(int fd, char *buffer, int size)
{
    int read_ret = 0;

    read_ret = read(fd, buffer, size);
    if (read_ret == -1)
        my_putstr("error");
    if (read_ret == 0)
        my_putstr("error");
    if (read_ret < size)
        my_putstr("good");
    if (read_ret == size)
        my_putstr("good");
}

void fs_cat_500_bytes(char const *filepath)
{
    char *buff = malloc(sizeof(char) * 501);
    int fd = open(filepath, O_RDONLY);

    read(fd, buff, 500);
    my_putstr(buff);
    my_putchar('\n');
    close(fd);
}

void fs_cat_x_bytes(char const *filepath, int x)
{
    int fd = open(filepath, O_RDONLY);
    char *buff = malloc(sizeof(char) * (x + 1));

    read(fd, buff, x);
    my_putstr(buff);
    close(fd);
}

void fs_print_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buff = malloc(sizeof(char) * 100000);

    read(fd, buff, 99999);
    for (int i = 0; buff[i] != '\n'; i++)
        my_putchar(buff[i]);
}
