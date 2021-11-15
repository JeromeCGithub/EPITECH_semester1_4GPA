/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** tests
*/

#include "../include/my.h"

Test(display_matrice, normal_test)
{
    float **matrice = init_matrice();

    cr_redirect_stdout();
    display_matrice(matrice);
    fflush(stdout);
    cr_assert_stdout_eq_str("1.00    0.00    0.00\n\
0.00    1.00    0.00\n0.00    0.00    1.00\n");
}

Test(display_matrice, test_nb_neg)
{
    float **matrice = init_matrice();

    matrice[0][1] = -1;
    matrice[0][2] = -1;
    matrice[0][0] = -1;
    cr_redirect_stdout();
    display_matrice(matrice);
    fflush(stdout);
    cr_assert_stdout_eq_str("-1.00   -1.00   -1.00\n\
0.00    1.00    0.00\n0.00    0.00    1.00\n");
}

Test(display_matrice, test_zero_neg)
{
    float **matrice = init_matrice();

    matrice[0][1] = -0.000000001;
    matrice[1][0] = -0.000000001;
    matrice[0][2] = -0.000000001;
    cr_redirect_stdout();
    display_matrice(matrice);
    fflush(stdout);
    cr_assert_stdout_eq_str("1.00    0.00    0.00\n\
0.00    1.00    0.00\n0.00    0.00    1.00\n");

}
