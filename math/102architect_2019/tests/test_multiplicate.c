/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** test multiplication
*/

#include "../include/my.h"

Test(multiply_matrice_pnt, test1)
{
    float **matrice = init_matrice();
    float *p = init_p(5, 4, 1);

    matrice[0][2] = 1;
    matrice[1][2] = 1;
    cr_redirect_stdout();
    multiply_matrice_pnt(p, matrice);
    fflush(stdout);
    cr_assert_stdout_eq_str("(5.00, 4.00) => (6.00, 5.00)\n");
}

Test(multiply_matrice, test2)
{
    float **matrice = init_matrice();
    float buffer[3][3] = {{2, 0, 0},
                          {0, -2, 0},
                          {0, 0, 1}};
    multiply_matrice(matrice, buffer);
    cr_assert_eq(matrice[0][0], 2);
    cr_assert_eq(matrice[0][1], 0);
    cr_assert_eq(matrice[0][2], 0);
    cr_assert_eq(matrice[1][0], 0);
    cr_assert_eq(matrice[1][1], -2);
    cr_assert_eq(matrice[1][2], 0);
    cr_assert_eq(matrice[2][0], 0);
    cr_assert_eq(matrice[2][1], 0);
    cr_assert_eq(matrice[2][2], 1);
}
