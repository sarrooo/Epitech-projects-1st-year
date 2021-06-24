/*
** EPITECH PROJECT, 2020
** My_put_uns
** File description:
** Put unsigned int
*/

void my_putchar(char c);

int my_put_uns(unsigned int nb, int base, char *av)
{
    if (nb < base && nb >= 0) {
        my_putchar(av[nb]);
        return (0);
    }
    if (base <= nb) {
        my_put_uns(nb / base, base, av);
        my_put_uns(nb % base, base, av);
    }
}
