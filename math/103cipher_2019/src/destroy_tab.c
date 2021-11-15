/*
** EPITECH PROJECT, 2019
** 103cipher
** File description:
** destroy tab
*/

#include <my.h>

void destroy_tab(tab_t *tab)
{
    for (int i = 0; i < tab->lines; i++)
        free(tab->matrice[i]);
    free(tab->matrice);
    free(tab);
}
