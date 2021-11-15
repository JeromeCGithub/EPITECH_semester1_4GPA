/*
** EPITECH PROJECT, 2020
** 106bombyx
** File description:
** bombyx
*/

#include <bombyx.h>

void bombyx1(double n, double k)
{
    for (int i = 0; i < 100; i++) {
        printf("%d %.2f\n", i + 1, n);
        n = k * n * (1000.0f - n) / 1000.0f;
    }
}

void bombyx2(double n, int i0, int i1)
{
    int i = 0;
    double save = n;

    for (double k = 100.0f; k <= 400.0f; k += 1.0f) {
        n = save;
        for (i = 1; i < i0; i++)
            n = k / 100.0f * n * (1000.0f - n) / 1000.0f;
        for (; i <= i1 ; i++) {
            printf("%.2f %.2f\n", k / 100.0f, n);
            n = k / 100.0f * n * (1000.0f - n) / 1000.0f;
        }
    }
}
