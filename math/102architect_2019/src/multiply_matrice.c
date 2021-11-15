/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** multiply two matrices
*/

#include "../include/my.h"

void multiply_simple(float matrice_tmp[3], float buffer[3], float *matrice)
{
    float result = 0;

    for (int i = 0; i < 3; i++)
        result += matrice_tmp[i] * buffer[i];
    *matrice = result;
}

void multiply_matrice(float **matrice, float buffer[3][3])
{
    float matrice_tmp[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matrice_tmp[i][j] = matrice[i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            multiply_simple(matrice_tmp[i], buffer[j], &matrice[i][j]);
}

void multiply_matrice_pnt(float *p, float **matrice)
{
    float result[3] = {0, 0, 0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i] += (p[j] * matrice[i][j]);
        }
    }
    printf("(%.2f, %.2f)", p[0], p[1]);
    printf(" => ");
    printf("(%.2f, %.2f)\n", result[0], result[1]);
}
