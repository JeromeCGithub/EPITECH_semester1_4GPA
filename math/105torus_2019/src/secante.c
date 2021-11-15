/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** secante
*/

#include <my.h>

void secante(char *av[])
{
    int n = atoi(av[N]);
    double x0 = 0;
    double x1 = 1;
    double temp = 0;
    double den = 0;
    int first_print = 0;

    for (int i = 0; (calc_result(av, x1) > pow(10, -n) || calc_result(av, x1) < 0) && i < 1000; i++) {
        temp = x1;
        den = calc_result(av, x1) - calc_result(av, x0);
        if (!den)
            exit(84);
        x1 = x1 - (calc_result(av, x1) * (x1 - x0)) / den;
        printf("x = %.*f\n", (first_print) ? n : 1, x1);
        first_print = 1;
        x0 = temp;
    }
}
