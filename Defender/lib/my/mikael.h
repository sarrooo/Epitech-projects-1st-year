/*
** EPITECH PROJECT, 2021
** Epitech
** File description:
** my_lib
*/

#ifndef my_lib
#define my_lib

//INCLUDE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <assert.h>
#include <stdarg.h>

//PROTOTYPES

void my_putchar(char c);
int my_compute_power_rec(int nb, int p);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_intlen_signed(int nb);
char *my_strcpy(char *dest, char const *src);
int my_printf(char *format, ...);
char *my_strdup(char const *src);
int my_strcmp(char const *s1, char const *s2);
void my_strcat_ahead(char *src, char *dest);
char *my_strcat(char *dest, char const *src);
char *str_int(int nb);

#endif /* !my_lib */
