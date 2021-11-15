/*
** EPITECH PROJECT, 2020
** 107transfer
** File description:
** tests error handling
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(test_error_handling, valide_tab)
{
    char *str[] = {"./107transfer", "2*2*3*-3", "2*2"};

    cr_assert_eq(error_handling(3, str), 0);
}

Test(test_error_handling, odd_arg)
{
    char *str[] = {"./107transfer", "2*2"};

    cr_assert_eq(error_handling(2, str), 1);
}

Test(test_error_handling, bad_arg1)
{
    char *str[] = {"107transfer", "e2*2", "q3*9we"};

    cr_assert_eq(error_handling(3, str), 1);
}

Test(test_error_handling, misplaced_less)
{
    char *str[] = {"107transfer", "2*2", "3-*9"};

    cr_assert_eq(error_handling(3, str), 1);
}

Test(test_error_handling, misplaced_less2)
{
    char *str[] = {"107transfer", "1*e2*2", "--3*9"};

    cr_assert_eq(error_handling(3, str), 1);
}

Test(test_error_handling, bad_ac)
{
    char *str[] = {"107transfer", "2*2", "--3*9"};

    cr_assert_eq(error_handling(6, str), 1);
}

Test(test_div_zero, test_engine_dive_zero)
{
    char *str[] = {"107transfer", "0*0", "0*0"};

    cr_redirect_stdout();
    cr_assert_eq(my_engine(3, str), 84);
}
