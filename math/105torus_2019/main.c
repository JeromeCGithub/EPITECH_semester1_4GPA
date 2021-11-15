/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** main
*/

#include <my.h>

int main(int ac, char **av)
{
    if (ac == 2)
        help(av[1]);
    error_handling(ac, av);
    switch (atoi(av[1])) {
    case 1:
        bisection(av);
        break;
    case 2:
        newton(av);
        break;
    case 3:
        secante(av);
        break;
    default:
        return (84);
    }
    return (0);
}
