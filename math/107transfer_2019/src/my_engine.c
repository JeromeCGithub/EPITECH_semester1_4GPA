/*
** EPITECH PROJECT, 2020
** 107transfer
** File description:
** my engine
*/

#include <my.h>

double horner(double poly[], int n, double x)
{
    double result = poly[n - 1];

    for (int i = n - 2; i >= 0; i--)
        result = result * x + poly[i];
    return (result);
}

int my_engine(int ac, char **av)
{
    double horner1 = 0;
    double horner2 = 0;
    double x = 0;
    double my_result = 1;
    rational_func_t **my_rational = parse(ac, av);

    for (x = 0 ; x <= 1.001 ; x += 0.001) {
        for (int i = 0 ; my_rational[i]; i++) {
            horner1 = horner(my_rational[i]->num, my_rational[i]->nb_num, x);
            horner2 = horner(my_rational[i]->den, my_rational[i]->nb_den, x);
            if (horner2 == 0.0f)
                return (84);
            my_result *= horner1 / horner2;
        }
        printf("%.3f -> %.5f\n", x, my_result);
        my_result = 1;
    }
    return (0);
}
