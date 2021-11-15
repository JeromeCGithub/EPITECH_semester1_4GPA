/*
** EPITECH PROJECT, 2019
** 101pong
** File description:
** test pong
*/

#include "../include/my.h"
#include <criterion/criterion.h>

Test(pong, test_pong6, .exit_code = 84)
{
    char *av[] = {"1", "1", "1", "1", "1", "1", "1", "-5"};

    error_cases(8, av);
}

Test(pong, test_pong7, .exit_code = 84)
{
    char *av[] = {"1", "1", "1", "1", "1", "1", "1", "5.5"};

    error_cases(8, av);
}

Test(pong, test_pong8, .exit_code = 84)
{
    char *av[] = {"1", "1", "1", "1", "1", "1", "1", "-5"};

    error_cases(8, av);
}

Test(pong, test_pong9)
{
    char *av[] = {"./101pong", "-h"};

    cr_redirect_stdout();
    error_cases(2, av);
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


Test(pong, test_pong10, .exit_code = 84)
{
    double n = 0;
    coord_t velocity;
    coord_t *ball_t1 = malloc(sizeof(coord_t));
    coord_t ball_tn;

    velocity.x = 0;
    velocity.y = 0;
    velocity.z = 0;
    ball_t1->x = 0;
    ball_t1->y = 0;
    ball_t1->z = 0;
    ball_tn.x = 0;
    ball_tn.y = 0;
    ball_tn.z = 0;
    print_it(velocity, ball_t1, ball_tn, n);
}
