/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <my.h>

int main(int ac, char **av)
{
    if (ac == 1)
        if (help(av))
            return (0);
    return (my_engine(ac, av));
}
