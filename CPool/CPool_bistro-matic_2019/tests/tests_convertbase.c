/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** test convert base
*/

#include "../include/my.h"
#include <criterion/criterion.h>

Test(my_strndog, test_catncat_nbtostr)
{
    cr_assert_str_eq(my_strndog("loll", "tes", 1), "lollt");
    cr_assert_str_eq(my_strcat("loll", "tes"), "lolltes");
    cr_assert_str_eq(my_nbtostr(51), "51");
    cr_assert_str_eq(subinf("-2", "-20"), "18");
}

Test(clean_str, test_convertbase)
{
    cr_assert_str_eq(clean_str("eryt", "sert25", "()y-*/%"), "12+3");
    cr_assert_str_eq(convert_to10(
                        clean_str("FF+FF", "0123456789ABCDEF",
                                "()+-*/%"), "0123456789ABCDEF"), "255+255");
    cr_assert_str_eq(reconvert("-101239", "0123456789ABCDEF",
                                "()+'*/%"), "'18B77");
    cr_assert_str_eq(reconvert("101239", "0123456789ABCDEF",
                                "()+'*/%"), "18B77");
    cr_assert_str_eq(reconvert("0", "0123456789ABCDEF", "()+-*/%"), "0");
}

Test(test_base10, test_test_base10)
{
    cr_assert_eq(test_base10("0123456789"), 1);
    cr_assert_eq(test_base10("012345A789"), 0);
    cr_assert_str_eq(convert_to10("15+15", "0123456789"), "15+15");
    cr_assert_str_eq(reconvert("45", "0123456789", "()+-*/%"), "45");
    cr_assert_str_eq(reconvert("-45", "0123456789", "()+B*/%"), "B45");
}

Test(convert_to10, tests_convert_to10)
{
    cr_assert_str_eq(convert_to10("101*(-10)", "01"), "5*(-2)");
    cr_assert_str_eq(convert_to10("+1", "01"), "+1");
}

Test(syntax_error, test_syntax_error)
{
    unknow_digit("", "()+-*/%", "0123456789");
}
