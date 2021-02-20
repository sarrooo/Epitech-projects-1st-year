/*
** EPITECH PROJECT, 2020
** BISTROMATEK
** File description:
** intlen
*/

int my_intlen_signed(int nb)
{
    int dec = nb;
    int i = 0;

    i = (dec == 0);
    if (dec < 0) {
        dec = -dec;
        i++;
    }
    for (; dec > 0; i++) {
        dec = dec / 10;
    }
    return (i);
}

int my_intlen(unsigned int nb)
{
    unsigned int dec = nb;
    unsigned int i = 0;

    i = (dec == 0);
    for (; dec > 0; i++) {
        dec = dec / 10;
    }
    return (i);
}

int my_intlen_hex(unsigned int nb)
{
    unsigned int hex = nb;
    unsigned int i = 0;

    i = (hex == 0);
    for (; hex > 0; i++) {
        hex = hex / 16;
    }
    return (i);
}

int my_intlen_oct(unsigned int nb)
{
    unsigned int oct = nb;
    unsigned int i = 0;

    i = (oct == 0);
    for (; oct > 0; i++) {
        oct = oct / 8;
    }
    return (i);
}

int my_intlen_bin(unsigned int nb)
{
    unsigned int bin = nb;
    unsigned int i = 0;

    i = (bin == 0);
    for (; bin > 0; i++) {
        bin = bin / 2;
    }
    return (i);
}
