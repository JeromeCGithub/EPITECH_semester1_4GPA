/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** test redir 6
*/

#include "../include/my.h"
#include "../include/bistromatic.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_s(void)
{
    cr_redirect_stderr();
}

Test(verif_op, test_veriof, .exit_code = 0, .init = redirect_s)
{
    verif_op("()+-*/%56");
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG, "");
}

Test(verif_op, test_veriof2, .exit_code = 84, .init = redirect_s)
{
    verif_op("()+-*//");
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG, "");
}

Test(verif_base, test_veriob3, .exit_code = 84, .init = redirect_s)
{
    verif_base("01123456789", "()+-*//");
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG, "");
}
