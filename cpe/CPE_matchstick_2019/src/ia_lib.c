/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** ia lib
*/

#include <my.h>

int find_nb_one_all(int *tab, int line)
{
    int nb = 0;

    for (int i = 0 ; i < line ; i++) {
        if (tab[i] == 1)
            nb++;
    }
    return (nb);
}

int is_balanced(int *tab, int line)
{
    int nb = 0;

    for (int bit = 31 ; bit >= 0 ; bit--) {
        for (int i = 0 ; i < line ; i++) {
            (tab[i] >> bit & 1) ? nb++ : nb;
        }
        if (nb % 2)
            return (bit);
    }
    return (-1);
}

int find_line(int *tab, int line, int bit)
{
    int tmp = 0;

    for (int i = 0 ; i < line ; i++) {
        if (tab[tmp] <= tab[i] && (tab[i] >> bit & 1))
            tmp = i;
    }
    return (tmp);
}

int end_of_game(int *tab, int line)
{
    int tmp = 0;

    for (int i = 0 ; i < line ; i++) {
        if (tab[i] > 1)
            tmp++;
    }
    if (tmp == 1)
        return (1);
    return (0);
}
