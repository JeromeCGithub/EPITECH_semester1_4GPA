/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** calc_result
*/

#include <my.h>

double calc_result(char **av, double x)
{
    return (atof(av[A0]) +
            atof(av[A1]) * x +
            atof(av[A2]) * pow(x, 2) +
            atof(av[A3]) * pow(x, 3) +
            atof(av[A4]) * pow(x, 4));
}
