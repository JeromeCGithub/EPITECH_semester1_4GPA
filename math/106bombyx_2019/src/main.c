/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <bombyx.h>

int main(int ac, char **av)
{
    if (ac < 3 || ac > 4) {
        if (help(av))
            return (0);
        else
            return (84);
    }
    if (error_handling(ac, av) == 84)
        return (84);
    if (ac == 3)
        bombyx1(atof(av[1]), atof(av[2]));
    else
        bombyx2(atof(av[1]), atoi(av[2]), atoi(av[3]));
    return (0);
}
