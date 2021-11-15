/*
** EPITECH PROJECT, 2019
** tests_redir
** File description:
** test redir
*/

#include "../include/my.h"
#include "../include/bistromatic.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

Test(putchar, test_putchar, .init = redirect_all_stdout)
{
    my_putchar('t');
    cr_assert_stdout_eq_str("t", "");
}

Test(putnbr, test_putnbr, .init = redirect_all_stdout)
{
    my_put_nbr(-50);
    cr_assert_stdout_eq_str("-50", "");
}

Test(putstr, test_putstr, .init = redirect_all_stdout)
{
    my_putstr("test");
    cr_assert_stdout_eq_str("test", "");
    my_putstr2("test");
    cr_assert_stderr_eq_str("test", "");
}

Test(is_function, test_is_function)
{
    cr_assert_eq(is_function('*'), 1);
    cr_assert_eq(is_function('d'), 0);
    cr_assert_eq(op_precedence('4', '+'), 0);
}
