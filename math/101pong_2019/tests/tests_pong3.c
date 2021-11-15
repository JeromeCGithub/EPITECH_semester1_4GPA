/*
** EPITECH PROJECT, 2019
** 101pong
** File description:
** test pong 3
*/

#include "../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(pong, test_pong11)
{
    char *av[] = {"./101pong", "1.1", "2", "6", "7", "7", "9", "2"};

    cr_redirect_stdout();
    vector_calc(av);
    fflush(stdout);
    cr_assert_stdout_eq_str("The velocity vector of the ball is:\n(5.90, 5.00,\
 3.00)\nAt time t + 2, ball coordinates will be:\n(18.80, 17.00, 15.00)\nThe\
 ball won't reach the paddle.\n");
}
