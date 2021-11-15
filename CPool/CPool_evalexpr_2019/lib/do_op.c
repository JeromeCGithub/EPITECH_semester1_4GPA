/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include <unistd.h>
#include "../include/my.h"

int do_op(char signe, int nb1, int nb2)
{
    switch (signe) {
    case '+':
        return (nb1 + nb2);
    case '-':
        return (nb1 - nb2);
    case '*':
        return (nb1 * nb2);
    case '/':
        return (nb1 / nb2);
    case '%':
        return (nb1 % nb2);
    default:
        return (0);
        break;
    }
}
