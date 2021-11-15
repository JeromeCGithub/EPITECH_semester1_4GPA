/*
** EPITECH PROJECT, 2019
** 101pong
** File description:
** test pong
*/

#include "../include/my.h"
#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(pong, test_pong1)
{
    char *av[] = {"./101pong", "1", "3", "5", "7", "9", "-2", "4"};

    cr_redirect_stdout();
    vector_calc(av);
    fflush(stdout);
    cr_assert_stdout_eq_str("The velocity vector of the ball is:\n(6.00, 6.00,\
 -7.00)\nAt time t + 4, ball coordinates will be:\n(31.00, 33.00, -30.00)\nThe\
 ball won't reach the paddle.\n");
}

Test(pong, test_pong2)
{
    char *av[] = {"./101pong", "1.1", "3", "5", "-7", "9", "2", "4"};

    cr_redirect_stdout();
    vector_calc(av);
    fflush(stdout);
    cr_assert_stdout_eq_str("The velocity vector of the ball is:\n(-8.10, 6.00,\
 -3.00)\nAt time t + 4, ball coordinates will be:\n(-39.40, 33.00, -10.00)\nThe\
 incidence angle is:\n16.57 degrees\n");
}

Test(pong, test_pong3)
{
    char av[] = "-h";

    cr_redirect_stdout();
    print_h(av);
    fflush(stdout);
    cr_assert_stdout_eq_str("USAGE\n\
    ./101pong x0 y0 z0 x1 y1 z1 n\n\n\
DESCRIPTION\n\
    x0  ball abscissa at time t - 1\n\
    y0  ball ordinate at time t - 1\n\
    z0  ball altitude at time t - 1\n\
    x1  ball abscissa at time\n\
    y1  ball ordinate at time\n\
    z1  ball altitude at time\n\
    n   time shift (greater than or equal to zero, integer)\n");
}

Test(pong, test_pong4, .exit_code = 84)
{
    char *av[] = {"./101pong", "1.1", "3", "5"};

    error_cases(4, av);
}

Test(pong, test_pong5, .exit_code = 84)
{
    char *av[] = {"./101pong", "1.1", "3", "5", "3", "A", "s", "d"};

    error_cases(8, av);
}
