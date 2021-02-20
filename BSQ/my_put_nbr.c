/*
** EPITECH PROJECT, 2020
** my_putnbr
** File description:
** display nb
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb < 10 && nb >= 0) {
        my_putchar(nb + 48);
        return (0);
    }
    if (10 <= nb) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * -1);
    }
}
