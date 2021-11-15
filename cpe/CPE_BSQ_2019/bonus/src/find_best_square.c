/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** find_best_square
*/

int check_nb(int **tab, int x, int y)
{
    int nb;

    nb = tab[y][x - 1];
    if (tab[y - 1][x - 1] < nb)
        nb = tab[y - 1][x - 1];
    if (tab[y - 1][x] < nb)
        nb = tab[y - 1][x];
    return (nb);
}

int **change_nb(int **tab, int x, int y)
{
    if (tab[y][x] == 0)
        return (tab);
    else if (tab[y][x] > 0) {
        tab[y][x] += check_nb(tab, x, y);
    }
    return (tab);
}

int **find_best_square(int **tab)
{
    int x = 0;
    int y = 0;

    for (y = 1 ; tab[y][0] != -1 ; y++) {
        for (x = 1 ; tab[y][x] != -1 ; x++) {
            tab = change_nb(tab, x, y);
        }
    }
    return (tab);
}
