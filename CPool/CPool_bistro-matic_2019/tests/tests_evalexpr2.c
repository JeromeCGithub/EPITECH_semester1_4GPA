/*
** EPITECH PROJECT, 2019
** testevalexpr2.c
** File description:
** testevalexpr 2
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/bistromatic.h"
#include <criterion/criterion.h>

Test(evalexpr, test_crash_evalexpr)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", string_traitement
                                ("-5-2-6+36-27--2"), 15), "-2");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", string_traitement
                                ("------5*-2/-6+36%-27--2"), 23), "12");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/&",
                                string_traitement
                                ("(979878+(89*26)---55--56/2+36)/2"),
                                32), "491100");
    cr_assert_str_eq(do_op('d', "12", "1"), "0");
    cr_assert_str_eq(mutinf("\0", "\0"), "0");
}

Test(modinf, test_modifn)
{
    cr_assert_str_eq(modinf("-2", "-2"), "-2");
    cr_assert_str_eq(modinf("-2", "-22"), "-22");
    cr_assert_str_eq(modinf("2", "-22"), "-22");
    cr_assert_str_eq(modinf("-2", "22"), "22");
    cr_assert_str_eq(modinf("-22", "-22"), "-22");
    cr_assert_str_eq(modinf("22", "-22"), "0");
    cr_assert_str_eq(modinf("-22", "22"), "0");
}

Test(divinf, testdivif)
{
    cr_assert_str_eq(divinf("465456", "23123"), "20");
    cr_assert_str_eq(divinf("-45598765456", "23123"), "-1972009");
    cr_assert_str_eq(divinf("465456", "-2397899123"), "0");
    cr_assert_str_eq(divinf("-465456", "-23123"), "20");
    cr_assert_str_eq(divinf("-4654", "-23455123"), "0");
    cr_assert_str_eq(divinf("-465456", "2312989893"), "0");
    cr_assert_str_eq(divinf("465499889556", "23123"), "20131466");
    cr_assert_str_eq(divinf("0", "-231"), "0");
    cr_assert_str_eq(divinf("46", "23"), "2");
}

Test(subbinf, subinfff)
{
    cr_assert_str_eq(subinf("-100", "-100"), "0");
    cr_assert_str_eq(subinf("-100", "-10"), "-90");
    cr_assert_str_eq(subinf("1000", "1"), "999");
}

Test(mutinf, test_mutinf)
{
    cr_assert_str_eq(mutinf("-5", "0"), "0");
}
