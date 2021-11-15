/*
** EPITECH PROJECT, 2019
** evalexpr
** File description:
** main
*/

#include <stdlib.h>
#include "include/my.h"

int eval_expr(char const *str)
{
    return (calc(to_npi(str)));
}

int main(int ac, char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}
