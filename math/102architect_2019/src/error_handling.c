/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** manage error
*/

#include "../include/my.h"

void is_alphanum(char c, char c_2)
{
    if ((c < '0' || c > '9') && c != '-')
        exit(84);
    else if (c == '-' && (c_2 < '-' || c_2 > '9'))
        exit(84);
}

void check_arg(char *str)
{
    for (int i = 1 ; str[i] != '\0' ; i++)
        if (str[i] != 't' && str[i] != 'z' && str[i] != 'r' && str[i] != 's')
            exit(84);
}

void check_nbr(char **av, int *i)
{
    if (!(av[1]))
        exit(84);
    if (av[0][1] == 't' || av[0][1] == 'z') {
        if (!(av[2]))
            exit(84);
        for (int j = 0 ; av[1][j] != '\0' ; j++)
            is_alphanum(av[1][j], av[1][j + 1]);
        for (int j = 0 ; av[2][j] != '\0' ; j++)
            is_alphanum(av[2][j], av[2][j + 1]);
        *i = *i + 3;
    }
    else if (av[0][1] == 'r' || av[0][1] == 's') {
        for (int j = 0 ; av[1][j] != '\0' ; j++)
            is_alphanum(av[1][j], av[1] [j + 1]);
        *i = *i + 2;
    }
    else
        exit(84);
}

void error_handling(char **av)
{
    int i = 0;

    for (i = 0 ; av[i] && i < 2; i++)
        for (int j = 0 ; av[i][j] != '\0' ; j++)
            is_alphanum(av[i][j], av[i][j + 1]);
    if (!(av[i]))
        exit(84);
    while (av[i]) {
        check_arg(av[i]);
        check_nbr(&av[i], &i);
    }
}
