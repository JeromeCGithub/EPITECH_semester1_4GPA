/*
** EPITECH PROJECT, 2019
** 104intersection
** File description:
** main
*/

#include <my.h>

static void intersections(char **av)
{
    switch (atoi(av[1])) {
    case 1:
        sphere(av);
        break;
    case 2:
        cylinder(av);
        break;
    case 3:
        cone(av);
        break;
    default:
        exit(84);
    }
}

int main(int ac, char **av)
{
    if (ac > 1)
        help(av[1]);
    if (ac == 9) {
        error_handling(ac, av);
        intersections(av);
    }
    else
        return (84);
    return (0);
}
