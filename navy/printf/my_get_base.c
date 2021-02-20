/*
** EPITECH PROJECT, 2020
** printf
** File description:
** get a base
*/

#include <stdlib.h>
int my_compute_power_rec(int nb, int p);
int my_putstr(char const *str);
int mikastrlen(char const *str);
char *my_revstr(char *str);
int my_strlen(char const *str);
int my_intlen(int nb);
void display_space(int length, int *flags);
int my_intlen_hex(unsigned int nb);
int my_intlen_oct(unsigned int nb);
int my_intlen_bin(unsigned int nb);
int warmup_display_space_base(int *flags, char format,
unsigned int nb, int nb_length);
void my_putchar(char c);
void display_zero(int length, int *flags);

int len_base(int *flags, char format, unsigned int nb)
{
    int nb_length = 0;

    if (format == 'p')
        nb_length = my_intlen_hex(nb) + 2;
    if (format == 'o')
        nb_length = my_intlen_oct(nb);
    if (format == 'x' || format == 'X')
        nb_length = my_intlen_hex(nb);
    if (format == 'b')
        nb_length = my_intlen_bin(nb);
    if (flags[4] == 1 && nb != 0) {
        if (format == 'x' || format == 'X')
            nb_length += 2;
        if (format == 'o')
            nb_length++;
    }
    nb_length = warmup_display_space_base(flags, format, nb, nb_length);
    return (nb_length);
}

int warmup_display_space_base(int *flags, char format,
unsigned int nb, int nb_length)
{
    int length = nb_length;

    if (format == 'p' && flags[0] == 1)
        length++;
    if (flags[2] == 0 && flags[1] == 0)
        display_space(length, flags);
    if (format == 'p' && flags[0] == 1)
        my_putchar('+');
    if (format == 'p' && flags[3] == 1)
        my_putchar(' ');
    if (format == 'p') {
        my_putstr("0x");
    }
    return (length);
}

void affichage_diese(char format, int *flags, int length, unsigned int nb)
{
    if (format == 'x' && nb != 0) {
        my_putstr("0x");
    }
    if (format == 'X' && nb != 0) {
        my_putstr("0X");
    }
    if (format == 'o' && nb != 0) {
        my_putstr("0");
    }
    if (flags[2] == 1 && flags[1] == 0) {
        display_zero(length, flags);
    }
    return;
}

void display_flags(char *str, int *flags, int length, int nb)
{
    my_revstr(str);
    my_putstr(str);
    if (nb == 0)
        my_putchar('0');
    if (flags[1] == 1) {
        display_space(length, flags);
    }
}

void my_printf_base(unsigned int nb, char *base, int *flags, char format)
{
    int base_length = my_strlen(base);
    int i;
    char *str;
    unsigned int result = nb;
    int length;

    length = len_base(flags, format, nb);
    if (flags[4] == 1)
        affichage_diese(format, flags, length, nb);
    for (i = 1; my_compute_power_rec(base_length, i) <= nb; i++)
        if (i > 64)
            break;
    str = malloc(sizeof(char) * i + 1);
    for (int k = 0; result != 0; k++) {
        str[k] = base[result % base_length];
        result = result / base_length;
    }
    str[i] = '\0';
    display_flags(str, flags, length, nb);
    return;
}
