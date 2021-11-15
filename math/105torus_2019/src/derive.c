/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** derive
*/

#include <my.h>

double derive(char **av, double x)
{
    return (1 * atof(av[A1]) +
            2 * atof(av[A2]) * x +
            3 * atof(av[A3]) * pow(x, 2) +
            4 * atof(av[A4]) * pow(x, 3));
}
