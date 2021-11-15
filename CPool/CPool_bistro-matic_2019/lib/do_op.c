/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "../include/my.h"

char *do_op(char signe, char const *nb1, char const *nb2)
{
    switch (signe) {
    case '+':
        return (addinf(nb1, nb2));
    case '-':
        return (subinf(nb1, nb2));
    case '*':
        return (mutinf(nb1, nb2));
    case '/':
        return (divinf(nb1, nb2));
    case '%':
        return (modinf(nb1, nb2));
    }
    return ("0");
}
