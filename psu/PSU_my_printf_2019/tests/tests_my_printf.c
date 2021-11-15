/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** test
*/

#include "../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_printf, test_1)
{
    cr_redirect_stdout();
    my_printf("%b %hhb %i %d", 5, 5, 23, 23);
    cr_assert_stdout_eq_str("101 101 23 23");
}

Test(my_printf, test_2)
{
    cr_redirect_stdout();
    my_printf("% d %% %# hhd %5.3d %zi %jd", 5, 5, 23, 23, 23);
    cr_assert_stdout_eq_str(" 5 %  5   023 23 23 0x17");
}

Test(my_printf, test_3)
{
    cr_redirect_stdout();
    my_printf("%b %u %c %hho % +.5d %+i %ju", 5, 5, 'c', 10, 10, 5, 120);
    cr_assert_stdout_eq_str("101 5 c 12 +00010 +5 120");
}

Test(my_printf, test_4)
{
    cr_redirect_stdout();
    my_printf("%s %.2s %5s", "salut", "salut", "salut");
    cr_assert_stdout_eq_str("salut sa salut");
}

Test(my_printf, test_5)
{
    char str[5] = "salut";

    str[2] = 10;
    str[5] = '\0';
    cr_redirect_stdout();
    my_printf("%p", 123456789123456789);
    cr_assert_stdout_eq_str("0x1b69b4bacd05f15");
}
