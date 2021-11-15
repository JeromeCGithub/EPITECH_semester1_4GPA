/*
** EPITECH PROJECT, 2019
** test_evalexpr.c
** File description:
** tests my evalexpr
*/

#include "../include/my.h"
#include "../include/bistromatic.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(to_npi, test_to_npi_simple_digids)
{
    cr_assert_str_eq(to_npi("2+2"), "2 2 + ");
    cr_assert_str_eq(to_npi("2-2"), "2 2 - ");
    cr_assert_str_eq(to_npi("2*2"), "2 2 * ");
    cr_assert_str_eq(to_npi("2/2"), "2 2 / ");
    cr_assert_str_eq(to_npi("2%2"), "2 2 % ");
    cr_assert_str_eq(to_npi("2+2+2"), "2 2 + 2 + ");
    cr_assert_str_eq(to_npi("2-2+2*5"), "2 2 - 2 5 * + ");
    cr_assert_str_eq(to_npi("-(12-(4*32))"), "12 4 32 * - - ");
    cr_assert_str_eq(to_npi("2-2+2*5"), "2 2 - 2 5 * + ");
    cr_assert_str_eq(to_npi("2-2+(-2)*5"), "2 2 - 0 2 - 5 * + ");
    cr_assert_str_eq(to_npi("2-2+2*5"), "2 2 - 2 5 * + ");
}

Test(to_npi, test_to_npi_negative_digids)
{
    cr_assert_str_eq(to_npi("-2-5"), "2 - 5 - ");
    cr_assert_str_eq(to_npi("-2*(-2)"), "2 0 2 - * - ");
    cr_assert_str_eq(to_npi("-2/(-2)"), "2 0 2 - / - ");
    cr_assert_str_eq(to_npi("2*(-5)/2+6-2+1*(-(5)/1)"),
                    "2 0 5 - * 2 / 6 + 2 - 1 0 5 1 / - * + ");
    cr_assert_str_eq(to_npi("2%(-2)+(-2)"), "2 0 2 - % 0 2 - + ");
}

Test(calc, test_calc)
{
    cr_assert_str_eq(calc("2 2 + "), "4");
    cr_assert_str_eq(calc("2 2 - "), "0");
    cr_assert_str_eq(calc("2 0 5 - * 2 / 6 + 2 - 1 0 5 1 / - * + "), "-6");
    cr_assert_str_eq(calc("2 0 2 - % 0 2 - + "), "-2");
    cr_assert_str_eq(calc("2 2 - 2 5 * + "), "10");
    cr_assert_str_eq(calc("2 - 2 * - "), "4");
    cr_assert_str_eq(calc("2 - 0 2 - * "), "4");
    cr_assert_str_eq(calc("10 - 0 5 - /"), "2");
    cr_assert_str_eq(calc("0 00 + "), "0");
    cr_assert_str_eq(calc("9 9 + "), "18");
    cr_assert_str_eq(calc("99 9 + "), "108");
    cr_assert_str_eq(calc("0 9 - 9 + "), "0");
    cr_assert_str_eq(calc("9 0 9 - + "), "0");
    cr_assert_str_eq(calc("0 1 - 15 +"), "14");
    cr_assert_str_eq(calc("5 0 9 - + "), "-4");
    cr_assert_str_eq(calc("1 0 10 - + "), "-9");
    cr_assert_str_eq(calc("10 0 55 - %"), "-55");
    cr_assert_str_eq(do_op('/' , "99", "-98"), "-1");
}

Test(evalexpr, test_evalexprr)
{
    int j = 1;
    char *output = malloc(sizeof(char) * 5);

    output[0] = '1';
    output[3] = '\0';
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "3*-5", 6), "-15");
    cr_assert_str_eq(add0("1+2", output, &j), "10 ");
    cr_assert_str_eq(string_traitement("12--12"), "12+12");
}

Test(evalexpr, test_evalexpr)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "2+2", 3), "4");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "2*-(2+2)", 8), "-8");
    cr_assert_str_eq(eval_expr("0123456789",
                                "()+-*/%", "2*-(2-(3*2))", 12), "8");
}
