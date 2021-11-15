/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** test redir 4
*/

#include <stdlib.h>
#include "../include/bistromatic.h"
#include "../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect__stdout(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

Test(synt_error, test_synterr, .exit_code = 84, .init = redirect__stdout)
{
    synt_error("\n");
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG, "");
}

Test(synt_error, test_esynterr, .exit_code = 84, .init = redirect__stdout)
{
    synt_error("(()");
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG, "");
}

Test(print_h, test_printh, .init = redirect__stdout)
{
    char *av[] = {"d", "-h", "d", 0};
    char *av2[] = {"./calc", "-1", 0};
    char *av3[] = {"./calc", "-he", 0};
    char *av4[] = {"./calc", "+h", 0};
    char *av5[] = {"./calc", "+he", 0};
    char *av6[] = {"./calc", "+Ae", 0};

    print_h(1, av);
    print_h(2, av);
    cr_assert_stdout_eq_str("USAGE\n./calc base operators \
size_read\n\nDESCRIPTION\n- base: all the symbols of the base\n- operators: \
the symbols for the parentheses and the 5 operators\n- size_read: number of ch\
aracters to be read\n", "");
    print_h(1, av6);
}
