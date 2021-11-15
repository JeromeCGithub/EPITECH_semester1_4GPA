/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <my.h>

int main(int ac, char **av)
{
    if (ac == 2)
        if (help(av))
            return (0);
    if (error_handling(ac, av))
        return (84);
    return (my_engine(ac, av));
}
