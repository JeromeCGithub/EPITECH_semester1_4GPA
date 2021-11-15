/*
** EPITECH PROJECT, 2019
** my_pushswap
** File description:
** main
*/

#include <my.h>

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    else if (ac < 3) {
        write(1, "\n", 1);
        return (0);
    }
    return (radix_s(ac, av));
}
