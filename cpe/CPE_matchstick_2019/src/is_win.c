/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** is win
*/

#include <my.h>

int is_win_ia(int *tab, int line)
{
    for (int i = 0 ; i < line ; i++)
        if (tab[i] > 0)
            return (0);
    write(1, "\nYou lost, too bad...\n", 22);
    return (1);
}

int is_win_player(int *tab, int line)
{
    for (int i = 0 ; i < line ; i++)
        if (tab[i] > 0)
            return (0);
    write(1, "\nI lost... snif... but I'll get you next time!!\n", 48);
    return (1);
}
