/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** tests_lib
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(get_nbr, test_getnbr)
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

Test(my_strndup, test_my_strndup)
{
    cr_assert_str_eq(my_strndup("lol", 2), "lo");
    cr_assert_str_eq(my_strndup("lol", 3), "lol");
}

Test(my_nbcmp, test_my_nbcmp)
{
    cr_assert_eq(my_nbcmp("50", "3"), 1);
    cr_assert_eq(my_nbcmp("52", "50"), 1);
    cr_assert_eq(my_nbcmp("5", "30"), -1);
    cr_assert_eq(my_nbcmp("30", "32"), -1);
    cr_assert_eq(my_nbcmp("50", "50"), 0);
    cr_assert_eq(my_nbcmp("50", "500"), -1);
}

Test(my_nblen, tests_my_nblen)
{
    cr_assert_eq(my_nblen("-A"), 1);
    cr_assert_eq(op_precedence('A', 'B'), 0);
}
