/*
** EPITECH PROJECT, 2020
** EPITECH PROJECT, 2020
** File description:
** display int
*/

void my_putchar(char c);
int my_intlen(unsigned int nb);
void display_space(int length, int *flags);
void display_zero(int length, int *flags);
int my_put_nbr(int nb);

int my_put_unsigned_nbr(unsigned int nb, int *flags)
{
    int nb_length = my_intlen(nb);
    if (flags[2] == 0 && flags[1] == 0)
        display_space(nb_length, flags);
    if (flags[2] == 1 && flags[1] == 0)
        display_zero(nb_length, flags);
    if (nb <= 9) {
        my_putchar(nb + 48);
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    if (flags[1] == 1) {
        display_space(nb_length, flags);
    }
    return (0);
}