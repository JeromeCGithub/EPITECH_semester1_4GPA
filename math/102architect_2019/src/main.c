/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** main
*/

#include "../include/my.h"

int main(int ac, char *av[])
{
    if (ac < 2)
        exit (84);
    if (ac == 2)
        print_h(av[1]);
    error_handling(&av[1]);
    parse_args(ac, av);
    return (0);
}
