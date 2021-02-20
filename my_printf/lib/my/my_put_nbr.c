/*
** EPITECH PROJECT, 2020
** my_putnbr
** File description:
** display nb
*/

void my_putchar(char c);

int my_put_uns(unsigned int nb, int base, char *av);

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
    if (nb == -2147483648)
        my_put_uns(2147483648, base, "0123456789");
}
