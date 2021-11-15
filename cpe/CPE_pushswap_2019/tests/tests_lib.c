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

Test(putnbr, putnbr1)
{
    cr_redirect_stdout();
    my_put_nbr(5);
    my_put_nbr(0);
    my_put_nbr(10);
    my_put_nbr(-5);
    my_put_nbr(-10);
    cr_assert_stdout_eq_str("5010-5-10");
}
