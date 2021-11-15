/*
** EPITECH PROJECT, 2019
** 103cipher
** File description:
** create_tab
*/

#include <my.h>

tab_t *create_tab(int lines, int columns)
{
    tab_t *tab = malloc(sizeof(tab_t));

    tab->lines = lines;
    tab->columns = columns;
    tab->matrice = malloc(sizeof(double *) * lines);
    for (int i = 0; i < lines; i++) {
        tab->matrice[i] = malloc(sizeof(double) * columns);
        for (int j = 0; j < columns; j++)
            tab->matrice[i][j] = 0.0;
    }
    return (tab);
}
