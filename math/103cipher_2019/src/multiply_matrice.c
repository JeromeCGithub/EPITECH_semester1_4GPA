/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** multiply two matrices
*/

#include "../include/my.h"

static void multiply_line(tab_t *result, tab_t *tab, tab_t *key, int i)
{
    for (int j = 0; j < key->columns; j++)
        for (int k = 0; k < tab->columns; k++)
            result->matrice[i][j] += tab->matrice[i][k] * key->matrice[k][j];
}

tab_t *multiply_matrice(tab_t *tab, tab_t *key)
{
    tab_t *result = create_tab(tab->lines, tab->columns);

    for (int i = 0; i < tab->lines; i++)
        multiply_line(result, tab, key, i);
    destroy_tab(tab);
    destroy_tab(key);
    return (result);
}
