/*
** EPITECH PROJECT, 2019
** 103cipher
** File description:
** display matrice
*/

#include <my.h>

void display_matrice(tab_t *tab)
{
    for (int i = 0; i < tab->lines; i++) {
        for (int j = 0; j < tab->columns; j++)
            printf("%f ", (char)tab->matrice[i][j]);
        printf("\n");
    }
}
