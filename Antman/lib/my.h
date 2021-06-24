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

int my_strcmp(char const *s1, char const *s2);

int my_strlen(char const *str);

char *my_revstr(char *str);

int my_strncmp(char const *s1, char const *s2, int n);

int my_printf(char *s, ...);

char *my_strncpy(char *dest, char const *src, int n);

int my_show_word_array(char * const *tab);

char *str_int(int nb);

#endif