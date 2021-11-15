/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** test my_printf 2
*/

#include "../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_printf, test_6)
{
    cr_redirect_stdout();
    my_printf("%0-d %-d %v", 10, 10);
    cr_assert_stdout_eq_str("10 10 %v");
}

Test(my_printf, test_7)
{
    cr_redirect_stdout();
    my_printf("%#x %#X %05d %0.2d %b %p", 10, 10, 5, 5, 0, 0);
    cr_assert_stdout_eq_str("0xa 0XA 00005 05 0 0x0");
}

Test(my_printf, test_8)
{
    cr_redirect_stdout();
    my_printf("%x %X %.5s %s", 0, 0, "lol", "ew");
    cr_assert_stdout_eq_str("0 0 lol ew");
}
