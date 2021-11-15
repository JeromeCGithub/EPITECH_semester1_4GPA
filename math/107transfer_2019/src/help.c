/*
** EPITECH PROJECT, 2020
** 106bombyx
** File description:
** help
*/

#include <string.h>
#include <stdio.h>

int help(char **av)
{
    if (!av[1] || strcmp("-h", av[1]))
        return 0;
    printf("USAGE\n");
    printf("\t%s [num den]*\n\n", av[0]);
    printf("DESCRIPTION\n");
    printf("\tnum\tpolynomial numerator defined by its coefficients\n");
    printf("\tden\tpolynomial denominator defined by its coefficients\n");
    return (1);
}
