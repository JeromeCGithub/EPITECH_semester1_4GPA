/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** test parser
*/

#include "../include/my.h"

Test(test_parser, test1)
{
    char *av[] = {"./102architect", "1", "2", "-t", "2", "3",
                  "-z", "1", "-2", "-r", "45", "-s", "30"};

    cr_redirect_stdout();
    parse_args(13, av);
    fflush(stdout);
    cr_assert_stdout_eq_str("Translation along vector (2, 3)\n\
Scaling by factors 1 and -2\n\
Rotation by a 45 degree angle\n\
Reflection over an axis with an inclination angle of 30 degrees\n\
0.97    -0.52   0.38\n\
0.26    1.93    6.31\n\
0.00    0.00    1.00\n\
(1.00, 2.00) => (0.31, 10.44)\n");
}
