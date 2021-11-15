/*
** EPITECH PROJECT, 2020
** 106bombyx
** File description:
** error handling
*/

#include <bombyx.h>

static int is_only_without_dot(char const *str)
{
    for (int i = 0 ; str[i] ; i++)
        if (str[i] > '9' || str[i] < '0')
            return (84);
}

static int is_only_num(char const *str)
{
    for (int i = 0 ; str[i] ; i++)
        if ((str[i] > '9' || str[i] < '0') && str[i] != '.')
            return (84);
}

int error_handling(int ac, char **av)
{
    if (ac < 3 || ac > 4)
        return (84);
    if (ac == 3 && (atof(av[2]) < 1 || atof(av[2]) > 4))
        return (84);
    for (int i = 1 ; i < ac ; i++) {
        if (is_only_num(av[i]) == 84)
            return (84);
    }
    if (ac == 4 && atoi(av[2]) > atoi(av[3]))
        return (84);
    if (ac == 4 && (!atof(av[2]) || !atof(av[3])))
        return (84);
    if (ac == 4 && (is_only_without_dot(av[2]) == 84 || is_only_without_dot(av[3]) == 84))
        return (84);
    return (0);
}
