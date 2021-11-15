/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** parse_args
*/

#include "../include/fptr.h"

void print_str(char **av)
{
    switch (av[0][1]) {
    case 't':
        printf("Translation along vector (%.0f, %.0f)\n",
                atof(av[1]), atof(av[2]));
        break;
    case 'z':
        printf("Scaling by factors %.0f and %.0f\n",
                atof(av[1]), atof(av[2]));
        break;
    case 'r':
        printf("Rotation by a %.0f degree angle\n", atof(av[1]));
        break;
    case 's':
        printf("Reflection over an axis with an ");
        printf("inclination angle of %.0f degrees\n", atof(av[1]));
        break;
    default:
        break;
    }
}

void parse_args(int ac, char **av)
{
    float *p = init_p(atof(av[1]), atof(av[2]), 1);
    float **matrice = init_matrice();

    for (int i = 3; i < ac; i++)
        if (av[i][0] == '-')
            print_str(&av[i]);
    for (int i = ac - 1; i >= 3; i--)
        if (av[i][0] == '-' && (av[i][1] < '0' || av[i][1] > '9'))
            (fptr[av[i][1] - 'r'])(matrice, &av[i]);
    display_matrice(matrice);
    multiply_matrice_pnt(p, matrice);
    free(p);
    for (int i = 0; i < 3; i++)
        free(matrice[i]);
    free(matrice);
}
