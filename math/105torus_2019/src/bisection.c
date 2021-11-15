/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** bisection
*/

#include <my.h>

void bisection(char *av[])
{
    int n = atoi(av[N]);
    int j = n - 1;
    double interval[2] = {0, 1};
    double c = 0.5;

    if (!(calc_result(av, c) > pow(10, -n) || calc_result(av, c) < 0))
        printf("x = 0.5\n");
    for (int i = 0; (calc_result(av, c) > pow(10, -n) || calc_result(av, c) < 0) && i < 1000; i++) {
        c = (interval[0] + interval[1]) / 2.0;
        printf("x = %.*f\n", n - j, c);
        if (calc_result(av, interval[0]) * calc_result(av, c) < 0)
            interval[1] = c;
        else
            interval[0] = c;
        if (j)
            j--;
    }
}
