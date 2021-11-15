/*
** EPITECH PROJECT, 2020
** 105 thorax
** File description:
** newton
*/

#include <my.h>

void newton(char **av)
{
    double x = 0.5;
    int n = atoi(av[N]);

    printf("x = %.1f\n", x);
    x = x - (calc_result(av, x) / derive(av, x));
    if (x >= 1)
        return;
    for (int i = 0; (calc_result(av, x) > pow(10, -n) || calc_result(av, x) < 0) && i < 1000; i++) {
        printf("x = %.*f\n", n, x);
        if (!derive(av, x))
            exit(84);
        x = x - (calc_result(av, x) / derive(av, x));
    }
    printf("x = %.*f\n", n, x);
}
