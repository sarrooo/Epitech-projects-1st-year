/*
** EPITECH PROJECT, 2020
** read_files 2/2
** File description:
** Read files
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c);

int my_putstr(char const *str);

int my_getnbr(char const *str);

int fs_get_number_from_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buff = malloc(sizeof(char) * 100000);
    int i = 0;
    char *dest;

    i = read(fd, buff, 99999);
    if (fd < 0 || i < 0)
        return (-1);
    for (i = 0; buff[i] != '\n' && buff[i] != 0; i++);
    dest = malloc(sizeof(char) * (i + 1));
    for (i = 0; buff[i] != '\n' && buff[i] != 0; i++) {
        if (buff[i] < 48 || buff[i] > 57)
            return (-1);
        dest[i] = buff[i];
    }
    dest[i] = 0;
    if (my_getnbr(dest) < 0 || my_getnbr(dest) == 0)
        return (-1);
    close(fd);
    return (my_getnbr(dest));
}
