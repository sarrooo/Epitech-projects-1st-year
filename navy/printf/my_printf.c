/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** display a content
*/

#include <stdarg.h>
#include <stdlib.h>
void my_putchar(char c);
int my_put_nbr(int nb, int *flags);
int my_putstr(char const *str);
void my_printf_base(unsigned int nb, char *base, int *flags, char format);
int my_putstr_octale(char const *str, int *flags);
void affichage_zero(int i);
int my_put_unsigned_nbr(unsigned int nb, int *flags);
int *scan_flags(char *format, int i, int *flags);
int my_getnbr(char const *str);
void display_space(int length, int *flags);
void my_putchar_flags(char c, int *flags);
int my_intlen(unsigned int nb);
int my_putstr_flags(char const *str, int *flags);
int my_put_nbr_flags(int nb, int *flags);

int display_args_after2(char car_format, va_list list_args, int *flags)
{
    switch (car_format) {
        case 'b':
            my_printf_base(va_arg(list_args, int), "01", flags, car_format);
            break;
        case 'p':
            my_printf_base(va_arg(list_args, int),
            "0123456789abcdef", flags, car_format);
            break;
        case '%':
            my_putchar('%');
            break;
        case '\0':
            break;
        default:
            my_putchar('%');
            my_putchar(car_format);
            break;
    }
}

int display_args_after(char car_format, va_list list_args, int *flags)
{
    switch (car_format) {
        case 'S':
            my_putstr_octale(va_arg(list_args, char *), flags);
            break;
        case 'x':
            my_printf_base(va_arg(list_args, int),
            "0123456789abcdef", flags, car_format);
            break;
        case 'X':
            my_printf_base(va_arg(list_args, int),
            "0123456789ABCDEF", flags, car_format);
            break;
        case 'u':
            my_put_unsigned_nbr(va_arg(list_args, int), flags);
            break;
        default:
            display_args_after2(car_format, list_args, flags);
            break;
        return (0);
    }
}

int display_args(char car_format, va_list list_args, int *flags)
{
    switch (car_format) {
        case 'd':
        case 'i':
            my_put_nbr_flags(va_arg(list_args, int), flags);
            break;
        case 'c':
            my_putchar_flags(va_arg(list_args, int), flags);
            break;
        case 's':
            my_putstr_flags(va_arg(list_args, char *), flags);
            break;
        case 'o':
            my_printf_base(va_arg(list_args, int), "01234567",
            flags, car_format);
            break;
        default:
            display_args_after(car_format, list_args, flags);
            break;
    }
    return (0);
}

int my_printf(char *format, ...)
{
    va_list list_args;
    int *flags = malloc(sizeof(int) * 8);

    va_start(list_args, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            for (int j = 0; j < 8; j++)
                flags[j] = 0;
            i++;
            scan_flags(format, i, flags);
            format += flags[5];
            display_args(format[i], list_args, flags);
        } else {
            my_putchar(format[i]);
        }
    }
    return (0);
}