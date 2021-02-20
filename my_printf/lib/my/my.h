/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** prototype of my_function
*/

#ifndef MY_H_

int my_getnbr(char const *str);

void my_putchar(char c);

int my_put_nbr(int nb, int base);

int my_put_uns(unsigned int nb, int base, char *av);

int my_putstr(char const *str);

char *my_revstr(char *str);

char *my_strcat(char *dest, char const *src);

int my_strcmp(char const *s1, char const *s2);

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb);

int my_strncmp(char const *s1, char const *s2, int n);

#endif /* MY_H_ */
