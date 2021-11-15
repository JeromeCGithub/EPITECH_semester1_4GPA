/*
** EPITECH PROJECT, 2019
** my_sort_word_array
** File description:
** Sort word in array.
*/

#include "include/my.h"

void compareit(char **av, int i, int j)
{
    char *ptr;

    if (my_strcmp(av[j], av[i]) == 1)
    {
        ptr = av[i];
        av[i] = av[j];
        av[j] = ptr;
    }
}

int my_sort_word_array(char **tab)
{
    int i = 0;
    int j = 0;

    for (i = 0 ; tab[i] != 0 ; i++)
    {
        for (j = 0 ; tab[j] != 0 ; j++)
            compareit(tab, i, j);
    }
    return (0);
}
