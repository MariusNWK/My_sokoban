/*
** EPITECH PROJECT, 2020
** my_putnbr
** File description:
** my_putnbr
*/
#include "../../include/my.h"
#include <unistd.h>

void my_putnbr(int nb)
{
    int i = 0;

    if (nb == -2147483648) {
        write(1, "-2147483648", 12);
        return;
    }
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }
    if (nb >= 10)
        my_putnbr(nb / 10);
    i = nb % 10 + 48;
    my_putchar(i);
}
