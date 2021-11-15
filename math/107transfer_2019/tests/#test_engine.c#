/*
** EPITECH PROJECT, 2020
** 107transfer
** File description:
** test my engine
*/

#include <my.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(test_my_parser, test_parser_num)
{
    char *str[] = {"107transfer", "2*2", "2*2"};
    rational_func_t **my_rational = parse(3, str);

    cr_assert_eq(my_rational[0]->num[0], 2);
}

Test(test_my_parser, test_parser_den)
{
    char *str[] = {"107transfer", "2*4", "1*7"};
    rational_func_t **my_rational = parse(3, str);

    cr_assert_eq(my_rational[0]->den[0], 1);
}

Test(test_my_engine, test_engine)
{
    char *str[] = {"107transfer", "2*2", "4*4"};

    cr_redirect_stdout();
    cr_assert_eq(my_engine(3, str), 0);
}
