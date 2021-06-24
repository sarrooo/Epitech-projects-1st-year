/*
** EPITECH PROJECT, 2020
** my_putnbr
** File description:
** display nb
*/

void my_putchar(char c);

int my_put_nbr(int nb, int base)
{
    if (nb < base && nb >= 0) {
        my_putchar(nb + 48);
        return (0);
    }
    if (base <= nb) {
        my_put_nbr(nb / base, base);
        my_put_nbr(nb % base, base);
    }
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * -1, base);
    }
}
