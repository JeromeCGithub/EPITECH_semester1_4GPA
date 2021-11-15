/*
** EPITECH PROJECT, 2019
** my_pushswap
** File description:
** test 1
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(pushswap, test1)
{
    char **av = malloc(sizeof(char) * 3);

    cr_redirect_stdout();
    av[1] = malloc(sizeof(char) * 1);
    av[1][0] = '2';
    av[2] = malloc(sizeof(char) * 1);
    av[2][0] = '1';
    radix_s(3, av);
    cr_assert_stdout_eq_str("pb ra pa ra pb pa sb\n");
    free(av[1]);
    free(av[2]);
    free(av);
}

Test(pushswap, test2)
{
    char **av = malloc(sizeof(char) * 3);

    cr_redirect_stdout();
    av[1] = malloc(sizeof(char) * 1);
    av[1][0] = '1';
    av[2] = malloc(sizeof(char) * 1);
    av[2][0] = '2';
    radix_s(3, av);
    cr_assert_stdout_eq_str("\n");
    free(av[1]);
    free(av[2]);
    free(av);
}

Test(pushswap, test3)
{
    char **av = malloc(sizeof(char) * 3);

    av[1] = malloc(sizeof(char) * 1);
    av[1][0] = '5';
    av[2] = malloc(sizeof(char) * 2);
    av[2][0] = '-';
    av[2][1] = '1';
    cr_redirect_stdout();
    radix_s(3, av);
    cr_assert_stdout_eq_str("ra ra pb ra pa ra ra pb ra pa pb ra pa pb ra pa p\
b ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb ra p\
a pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb r\
a pa pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa r\
ra sb\n");
    free(av[1]);
    free(av[2]);
    free(av);
}

Test(pushswap, test4)
{
    char **av = malloc(sizeof(char) * 5);

    av[0] = malloc(sizeof(char));
    av[1] = malloc(sizeof(char) * 1);
    av[1][0] = '5';
    av[2] = malloc(sizeof(char) * 2);
    av[2][0] = '-';
    av[2][1] = '1';
    cr_redirect_stdout();
    radix_s(3, av);
    cr_assert_stdout_eq_str("ra ra pb ra pa ra ra pb ra pa pb \
ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb \
ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa p\
b ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa \
pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa pb ra pa \
rra sb\n");
    pa(NULL, NULL);
    pb(NULL, NULL);
}
