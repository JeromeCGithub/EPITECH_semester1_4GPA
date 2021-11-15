/*
** EPITECH PROJECT, 2019
** test_redir2.c
** File description:
** test redir2
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/bistromatic.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_al_stdout(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

Test(test_malloc, test_testmalloc, .exit_code = 84, .init = redirect_al_stdout)
{
    void *ptr = NULL;

    test_malloc(ptr);
    cr_assert_stderr_eq_str(ERROR_MSG, "");
}

Test(divinf, test_div0, .exit_code = 84, .init = redirect_al_stdout)
{
    divinf("0", "0");
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG, "");
}

Test(modinf, test_mod0, .exit_code = 84, .init = redirect_al_stdout)
{
    modinf("0", "0");
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG, "");
}

Test(error_handling, test_errhan, .exit_code = 84, .init = redirect_al_stdout)
{
    eval_expr("0123456789", "()+-*/%", "/2+2", 4);
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG, "");
}
