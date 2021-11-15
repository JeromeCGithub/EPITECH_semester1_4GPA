/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** test redir3
*/

#include "../include/my.h"
#include "../include/bistromatic.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_a_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(unknow_digit, test_unknowdi, .exit_code = 84, .init = redirect_a_stdout)
{
    unknow_digit("2*h", "()+-*/%", "0123456789");
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG, "");
}

Test(unknow_digit, test_unknoswdi, .exit_code = 84, .init = redirect_a_stdout)
{
    unknow_digit("2l2", "()+-*/%", "0123456789");
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG, "");
}

Test(unknow_digit, test_unknwowdi)
{
    cr_assert_eq(is_inbase('2', "0123456789", "()+-*/%"), 1);
    cr_assert_eq(is_operand2('*', "()+-*/%"), 1);
}

Test(synt_error, test_synterror, .exit_code = 84, .init = redirect_a_stdout)
{
    synt_error(")");
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG, "");
}
