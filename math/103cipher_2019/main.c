/*
** EPITECH PROJECT, 2019
** 103cipher
** File description:
** main
*/

#include <my.h>

void check_arg(char **av)
{
    if ((av[3][0] != '0' && av[3][0] != '1') || av[3][1] != '\0')
        exit(84);
    if (av[3][0] == '1') {
        for (int i = 0 ; av[1][i] != '\0' ; i++)
            if (av[1][i] != ' ' && (av[1][i] > '9' || av[1][i] < '0') && av[1][i] != '-')
                exit(84);
    }
}

int main(int ac, char **av)
{
    if (ac != 4)
        return (84);
    check_arg(av);
    help(av[1]);
    if (av[3][0]) {
        if (av[3][0] == '0')
            encode(av[1], av[2]);
        if (av[3][0] == '1')
            decode(av[1], av[2]);
    }
    return (0);
}
