/*
** EPITECH PROJECT, 2020
** 107transfer
** File description:
** error handling
*/

#include <my.h>

int check_args(char **av)
{
    for (int i = 0; av[i]; i++) {
        for (int j = 0; av[i][j]; j++) {
            if (av[i][j] != '*' && av[i][j] != '-' && (av[i][j] > '9' || av[i][j] < '0'))
                return (1);
            else if ((av[i][j] == '*')
                && (!av[i][j + 1] || ((av[i][j + 1] < '0' || av[i][j + 1] > '9') && av[i][j + 1] != '-')))
                return (1);
            else if ((av[i][j] == '-')
                && (!av[i][j + 1] || (av[i][j + 1] < '0' || av[i][j + 1] > '9')))
                return (1);
        }
    }
    return (0);
}

int error_handling(int ac, char **av)
{
    if (ac < 3 || !(ac % 2))
        return (1);
    return (check_args(&av[1]));
}
