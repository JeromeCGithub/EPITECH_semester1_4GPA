/*
** EPITECH PROJECT, 2020
** 107transfer
** File description:
** test help file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(test_help, test_help_func_true)
{
    char *str[] = {"107transfer", "-h"};

    cr_redirect_stdout();
    cr_assert_eq(help(str), 1);
}

Test(test_help, test_help_func_false)
{
    char *str[] = {"107transfer", "lolilol"};
    char *str2[] = {"107transfer"};

    cr_assert_eq(help(str), 0);
    cr_assert_eq(help(str2), 0);
}
