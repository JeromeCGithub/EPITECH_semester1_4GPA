/*
** EPITECH PROJECT, 2020
** 106bombyx
** File description:
** help
*/

#include <bombyx.h>

int help(char **av)
{
    if (!av[1] || strcmp("-h", av[1]))
        return 0;
    printf("USAGE\n");
    printf("\t%s n [k | i0 i1]\n\n", av[0]);
    printf("DESCRIPTION\n");
    printf("\tn\tnumber of first generation indeividuals\n");
    printf("\tk\tgrowth rate from 1 to 4\n");
    printf("\ti0\tinitial generation (included)\n");
    printf("\ti1\tfinal generation (included)\n");
}
