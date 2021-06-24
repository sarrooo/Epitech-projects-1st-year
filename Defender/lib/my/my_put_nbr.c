/*
** EPITECH PROJECT, 2020
** EPITECH PROJECT, 2020
** File description:
** display int
*/

void my_putchar(char c);
int my_intlen_signed(int nb);
void display_space(int length, int *flags);
void display_zero(int length, int *flags);
int my_put_nbr(int nb);

int tools_flags_put_nbr(int nb, int *flags)
{
    int nb_length = my_intlen_signed(nb);

    if (flags[0] > 0 && nb > -1)
        nb_length++;
    if (flags[3] > 0 && nb > -1)
        nb_length++;
    if (flags[2] == 0 && flags[1] == 0)
        display_space(nb_length, flags);
    if (flags[0] > 0 && nb > -1)
        my_putchar('+');
    if (flags[3] > 0 && nb > -1)
        my_putchar(' ');
    if (flags[2] == 1 && nb > -1 && flags[1] == 0)
        display_zero(nb_length, flags);
    return (nb_length);
}

int my_put_nbr_flags(int nb, int *flags)
{
    int nb_length = tools_flags_put_nbr(nb, flags);
    if (nb < 0) {
        my_putchar('-');
        if (flags[2] == 1 && flags[1] == 0)
            display_zero(nb_length, flags);
        nb = -nb;
    } if (nb <= 9) {
        my_putchar(nb + 48);
    } else {
        flags[0] = 0;
        flags[3] = 0;
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    if (flags[1] == 1) {
        display_space(nb_length, flags);
    }
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    } if (nb <= 9) {
        my_putchar(nb + 48);
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return (0);
}
