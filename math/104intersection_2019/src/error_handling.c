/*
** EPITECH PROJECT, 2020
** 104inter
** File description:
** error handling here
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

static void check_param(char **av)
{
    if (atof(av[1]) == 1 || atof(av[1]) == 2)
        if (atoi(av[8]) < 0)
            exit(84);
    if (atof(av[1]) == 3)
        if (atof(av[8]) <= 0 || atof(av[8]) >= 90)
            exit(84);
    if (atof(av[1]) != 1 && atof(av[1]) != 2 && atof(av[1]) != 3)
        exit(84);
}

void error_handling(int ac, char **av)
{
    check_letter(ac, av);
    check_param(av);
}
