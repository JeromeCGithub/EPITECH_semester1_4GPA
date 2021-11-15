/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** init_var
*/

#include "../include/my.h"

float *init_p(float x, float y, float z)
{
    float *p = malloc(sizeof(float) * 3);

    p[0] = x;
    p[1] = y;
    p[2] = z;
    return (p);
}

float **init_matrice(void)
{
    float **matrice = malloc(sizeof(float *) * 3);

    for (int i = 0; i < 3; i++)
        matrice[i] = malloc(sizeof(float) * 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrice[i][j] = 0;
        }
    }
    for (int i = 0; i < 3; i++)
        matrice[i][i] = 1;
    return (matrice);
}
