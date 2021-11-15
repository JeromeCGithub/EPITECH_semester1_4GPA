/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** fonctions that modify matrice
*/

#include "../include/my.h"

void reflection(float **matrice, char **av)
{
    float angle = atof(av[1]) * M_PI / 180;
    float buffer[3][3] = {cos(2 * angle), sin(2 * angle), 0,
                          sin(2 * angle), -cos(2 * angle), 0,
                          0, 0, 1};

    multiply_matrice(matrice, buffer);
}

void rotation(float **matrice, char **av)
{
    float angle = atof(av[1]) * M_PI / 180;
    float buffer[3][3] = {cos(angle), sin(angle), 0,
	                  -sin(angle), cos(angle), 0,
                          0, 0, 1};

    multiply_matrice(matrice, buffer);
}

void scaling(float **matrice, char **av)
{
    float buffer[3][3] = {{atof(av[1]), 0, 0},
                          {0, atof(av[2]), 0},
                          {0, 0, 1}};

    multiply_matrice(matrice, buffer);
}

void translation(float **matrice, char **av)
{
    float buffer[3][3] = {{1, 0, 0},
                          {0, 1, 0},
                          {atof(av[1]), atof(av[2]), 1}};

    multiply_matrice(matrice, buffer);
}
