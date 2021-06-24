/*
** EPITECH PROJECT, 2020
** EPITECH PROJECT, 2020
** File description:
** day4
*/

void my_putchar(char c);
void my_printf_base(unsigned int nb, char *base, int *flags, char format);
int my_strlen_octale(char const *str);
void display_space(int length, int *flags);

void affichage_zero(int i)
{
    if (i < 8) {
        my_putchar('0');
        my_putchar('0');
    } else if (i < 80) {
        my_putchar('0');
    } else {
        return;
    }
    return;
}

int my_putstr_octale(char const *str, int *flags)
{
    int i;
    int flag_width = flags[6];

    if (flags[1] == 0)
        display_space(my_strlen_octale(str), flags);
    i = 0;
    flags[6] = 0;
    while (str[i] != '\0') {
        if (str[i] < 32 || str[i]>= 127) {
            my_putchar('\\');
            affichage_zero(str[i]);
            my_printf_base(str[i], "01234567", flags, 'S');
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
    flags[6] = flag_width;
    if (flags[1] == 1)
        display_space(my_strlen_octale(str), flags);
    return (0);
}
