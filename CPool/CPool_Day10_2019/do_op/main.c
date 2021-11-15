/*
** EPITECH PROJECT, 2019
** main of do_op
** File description:
** main of do_op.
*/

#include <unistd.h>

int my_get_nbr_pimped(char const *str);

int my_put_nbr(int nb);

void my_putchar(char c);

int my_addvalue(char *nbs1, char operator, char *nbs2)
{
    int nb1 = 0;
    int nb2 = 0;

    nb1 = my_get_nbr_pimped(nbs1);
    nb2 = my_get_nbr_pimped(nbs2);
    if (operator == '+')
        return (nb1 + nb2);
    else if (operator == '-')
        return (nb1 - nb2);
    return (0);
}

int my_dividvalue(char *nbs1, char operator, char *nbs2)
{
    int nb1 = 0;
    int nb2 = 0;

    nb1 = my_get_nbr_pimped(nbs1);
    nb2 = my_get_nbr_pimped(nbs2);
    if (operator == '%' && nb2 != 0)
        return (nb1 % nb2);
    else if (operator == '/' && nb2 != 0)
        return (nb1 / nb2);
    return (0);
}

int do_op(char **argv)
{
    int nb = 0;

    if (argv[2][0] == '+' || argv[2][0] == '-')
        nb = my_addvalue(argv[1], argv[2][0], argv[3]);
    else if (argv[2][0] == '%' || argv[2][0] == '/')
        nb = my_dividvalue(argv[1], argv[2][0], argv[3]);
    return (nb);
}

int return_84_or_number(char **av, int nb)
{
    if (av[2][0] != '+' && av[2][0] != '-'
        && av[2][0] != '/' && av[2][0] != '%')
        return (84);
    return (0);
}

int main(int argc, char **argv)
{
    int nb = 0;

    if (argc != 4)
        return (84);
    if (my_get_nbr_pimped(argv[3]) == 0 &&
        argv[2][0] == '/' && argv[3][0] == '0') {
        write(2, "Stop: division by zero\n", 23);
        return (84);
    }
    else if (my_get_nbr_pimped(argv[3]) == 0 &&
            argv[2][0] == '%' && argv[3][0] == '0') {
        write(2, "Stop: modulo by zero\n", 21);
        return (84);
    }
    nb = do_op(argv);
    my_put_nbr(nb);
    my_putchar('\n');
    return (return_84_or_number(argv, nb));
}
