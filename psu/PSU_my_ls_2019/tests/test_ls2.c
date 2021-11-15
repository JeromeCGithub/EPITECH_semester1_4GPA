/*
** EPITECH PROJECT, 2020
** my ls
** File description:
** test my ls
*/

#include <my.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(test_myls, test5, .exit_code = 84)
{
    char *av[] = {"./my_ls", "-zxcvbn"};

    cr_redirect_stderr();
    my_ls(2, av, 0);
}

Test(test_myls, test7)
{
    char **av = malloc(sizeof(char *) * 2);

    av[0] = malloc(sizeof(char) * 1);
    av[1] = malloc(sizeof(char) * 6);
    av[1][0] = '-';
    av[1][1] = 'r';
    av[1][2] = 't';
    av[1][3] = 'R';
    av[1][4] = 'l';
    av[1][5] = '\0';
    cr_redirect_stdout();
    my_ls(2, av, 0);
}
