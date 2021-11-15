/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** test lib
*/

#include "../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_getnbr, test_getnbr)
{
    cr_assert_eq(my_getnbr("500"), 500);
    cr_assert_eq(my_getnbr("dwqdwq500"), 500);
    cr_assert_eq(my_getnbr("-fdsa---+fdsadf"), 0);
    cr_assert_eq(my_getnbr("500jiklmu"), 500);
    cr_assert_eq(my_getnbr("-fdsa-30--+fdsadf30"), 30);
    cr_assert_eq(my_getnbr("2"), 2);
    cr_assert_eq(my_getnbr("-500"), -500);
    cr_assert_eq(my_getnbr("--500"), 500);
    cr_assert_eq(my_getnbr("500fewfew"), 500);
    cr_assert_eq(my_getnbr("-500fewfew"), -500);
    cr_assert_eq(my_getnbr("-+++++-500fewfew"), 500);
    cr_assert_eq(my_getnbr("546556156156561005555555555"), 0);
    cr_assert_eq(my_getnbr(NULL), 0);
    cr_assert_eq(my_getnbr("\0"), 0);
    cr_assert_eq(my_getnbr(""), 0);
    cr_assert_eq(my_getnbr("AAAAAAAAAAAAAAA"), 0);
}

Test(put_str, test_putstr1)
{
    cr_redirect_stderr();
    my_putstr2("lol");
    cr_assert_stderr_eq_str("lol");
}

Test(bsq, test_12)
{
    cr_assert_eq(bsq(2, "tests/mouli_maps/error4"), 84);
}

Test(bsq, test_13)
{
    cr_assert_eq(bsq(2, "tests/mouli_maps/error5"), 84);
}
