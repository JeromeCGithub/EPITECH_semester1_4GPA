/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** test my printf
*/

#include "../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_printf, test_15)
{
    cr_redirect_stdout();
    my_printf("%hhd %s %x %hX %5.2d", 23, "tr", 255, 255, 5);
    cr_assert_stdout_eq_str("23 tr ff FF    05");
}

Test(my_printf, test_16)
{
    cr_redirect_stdout();
    my_printf("%-0d %5s %hd %lu %llu", 3, "sal", 5, 9, -9223372036854775);
    cr_assert_stdout_eq_str("3   sal 5 9 18437520701672696841");
}

Test(my_printf, test_17)
{
    cr_redirect_stdout();
    my_printf("%5.2s %tu %zu %3c", "salut", 10, 10, 'e');
    cr_assert_stdout_eq_str("   sa 10 10   e");
}

Test(my_printf, test_18)
{
    char str[5] = "salut";

    str[2] = 10;
    str[5] = '\0';
    cr_redirect_stdout();
    my_printf("%.2u yo les gens %S %lld %ld %td %zd", 15, str, 0, 0, 0, 0);
    cr_assert_stdout_eq_str("15 yo les gens sa\\012ut 0 0 0 0");
}
