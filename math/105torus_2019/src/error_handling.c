/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** error handling
*/

#include <my.h>

static void check_letter(int ac, char **av)
{
    for (int i = 1 ; av[i] ; i++) {
        for (int j = 0 ; av[i][j] != '\0' ; j++) {
            if (av[i][j] != '-' && av[i][j] != '.' && (av[i][j] > '9' || av[i][j] < '0'))
                exit(84);
        }
    }
}

void error_handling(int ac, char **av)
{
    if (ac != 8)
        exit(84);
    check_letter(ac, av);
    if (atoi(av[N]) < 0)
        exit(84);
}
