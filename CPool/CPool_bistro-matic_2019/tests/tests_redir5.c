/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** test redir 5
*/

#include "../include/my.h"
#include "../include/bistromatic.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_stdout(void)
{
    cr_redirect_stderr();
}

Test(verif_expr, test_verifexpr, .exit_code = 84, .init = redirect_stdout)
{
    verif_expr("2**2", "()+-*/%");
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG, "");
}

Test(verif_string, test_verifstring, .exit_code = 84, .init = redirect_stdout)
{
    verif_string("())())(()()()()))((())()");
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG, "");
}

Test(verif_base, test_verifbase, .exit_code = 84, .init = redirect_stdout)
{
    verif_base("012345*789", "()+-*/%");
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG, "");
}

Test(clean_str, test_cleans, .exit_code = 84, .init = redirect_stdout)
{
    clean_str("fwpfekpfew", "0123456789", "()+-*/%");
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG, "");
}
