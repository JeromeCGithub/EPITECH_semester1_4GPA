/*
** EPITECH PROJECT, 2019
** is_error
** File description:
** Check if there is an error.
*/

#include "include/my.h"

int is_argument_ok(int ac, char **av)
{
    for (int i = 2 ; i < ac ; i++)
    {
        if (my_strlen(av[i]) != 1)
            return (1);
        else if ((av[i][0] > 'z' || av[i][0] < 'a')
                && (av[i][0] > 'Z' || av[i][0] < 'A'))
            return (1);
    }
    return (0);
}

int is_error(int ac, char **av)
{
    if (ac < 3)
        return (1);
    else if (av[1][0] == '\0')
        return (1);
    else
        return (is_argument_ok(ac, av));
}
