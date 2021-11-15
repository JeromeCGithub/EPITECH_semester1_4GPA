/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** display matrice
*/

#include "../include/my.h"

void display_matrice(float **matrice)
{
    for (int i = 0; i < 3; i++) {
        if (matrice[i][0] < 0 && matrice[i][0] > -0.001)
            matrice[i][0] *= -1;
        if (matrice[i][1] < 0 && matrice[i][1] > -0.001)
            matrice[i][1] *= -1;
        if (matrice[i][2] < 0 && matrice[i][2] > -0.001)
            matrice[i][2] *= -1;
        printf("%-7.2f %-7.2f %.2f\n", matrice[i][0],
               matrice[i][1], matrice[i][2]);
    }
}
