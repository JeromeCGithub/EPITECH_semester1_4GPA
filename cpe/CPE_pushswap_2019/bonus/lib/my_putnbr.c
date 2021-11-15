/*
** EPITECH PROJECT, 2019
** my_putnbr
** File description:
** put a nbr
*/

#include "../include/my.h"

void my_put_nbr(int nb)
{
    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    else
        my_putchar(nb + '0');
}
