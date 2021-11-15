/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** ia lib 2
*/

#include <my.h>

void impaire_coup(int *tab, game_t *game, int *nb_least)
{
    for (int i = 0 ; i < game->line ; i++) {
        if (tab[i] > 1) {
            (tab[i] < game->matchs) ?
                (*nb_least = tab[i]) : (*nb_least = game->matchs);
            (tab[i] < game->matchs) ? (tab[i] = 0) : (tab[i] -= game->matchs);
            write(1, "AI removed ", 11);
            my_put_nbr(*nb_least);
            write(1, " match(es) from line ", 21);
            my_put_nbr(i + 1);
            write(1, "\n", 1);
        }
    }
}

void paire_coup(int *tab, game_t *game, int *nb_least)
{
    for (int i = 0 ; i < game->line ; i++) {
        if (tab[i] > 1) {
            *nb_least = tab[i] - 1;
            tab[i] = 1;
            write(1, "AI removed ", 11);
            my_put_nbr(*nb_least);
            write(1, " match(es) from line ", 21);
            my_put_nbr(i + 1);
            write(1, "\n", 1);
        }
    }
}
