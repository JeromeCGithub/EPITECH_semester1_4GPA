/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** test printh
*/

#include "../include/my.h"

Test(print_h, test_print_h)
{
    char *str = "-h";

    cr_redirect_stdout();
    print_h(str);
    fflush(stdout);
    cr_assert_stdout_eq_str("USAGE\n\
    ./102architect x y transfo1 arg11 [arg12] [transfo2 arg12 [arg22]] ...\n\
DESCRIPTION\n\
    x   abscissa of the original point\n\
    y   ordinate of the original point\n\n\
    transfo arg1 [arg2]\n\
    -t i j  translation along vector (i, j)\n\
    -z m n  scaling by factors m (x-axis) and n (y-axis)\n\
    -r d    rotation centered in O by a d degree angle\n\
    -s d    reflection over the axis passing through O with an inclination\n\
            angle of d degrees\n");
}

Test(print_h, test_print_h2, .exit_code = 84)
{
    char *str = "-he";

    print_h(str);
}

Test(print_h, test_print_h3, .exit_code = 84)
{
    char *str = "aa";

    print_h(str);
}

Test(print_h, test_print_h4, .exit_code = 84)
{
    char *str = "-a";

    print_h(str);
}
