/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** input tab int
*/

#include <stdlib.h>

int **swap_nb(char **tab, int **tab_int)
{
    int i = 0;
    int j = 0;

    for (i = 0 ; tab[i] != 0 ; i++) {
        for (j = 0 ; tab[i][j] != '\n' && tab[i][j] != '\0' ; j++) {
            (tab[i][j] == '.') ? tab_int[i][j] = 1 : tab_int[i][j];
            (tab[i][j] == 'o') ? tab_int[i][j] = 0 : tab_int[i][j];
        }
        tab_int[i][j] = -1;
    }
    tab_int[i][0] = -1;
    return (tab_int);
}

int **input_tabint(char **tab)
{
    int **tab_int;
    int nb_line;
    int nb_co = 0;

    for (nb_line = 0 ; tab[nb_line] != 0 ; nb_line++);
    tab_int = malloc(sizeof(int *) * (nb_line + 1));
    if (tab_int == NULL)
        return (NULL);
    for (nb_co = 0 ; tab[0][nb_co] != '\n' && tab[0][nb_co] != '\0' ; nb_co++);
    for (int i = 0 ; i < nb_line + 1 ; i++) {
        tab_int[i] = malloc(sizeof(int) * (nb_co + 1));
        if (tab_int[i] == NULL)
            return (NULL);
    }
    tab_int = swap_nb(tab, tab_int);
    return (tab_int);
}
