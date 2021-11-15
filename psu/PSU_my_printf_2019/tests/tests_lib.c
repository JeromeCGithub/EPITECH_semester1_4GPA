/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** testlib
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
