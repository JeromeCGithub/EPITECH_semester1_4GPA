/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** test_init
*/

#include "../include/my.h"

Test(init_p, test1)
{
    float *p = init_p(23, -12, 48);

    cr_assert_eq(p[0], 23);
    cr_assert_eq(p[1], -12);
    cr_assert_eq(p[2], 48);
}

Test(init_matrice, test2)
{
    float **matrice = init_matrice();

    cr_assert_eq(matrice[0][0], 1);
    cr_assert_eq(matrice[0][1], 0);
    cr_assert_eq(matrice[0][2], 0);
    cr_assert_eq(matrice[1][0], 0);
    cr_assert_eq(matrice[1][1], 1);
    cr_assert_eq(matrice[1][2], 0);
    cr_assert_eq(matrice[2][0], 0);
    cr_assert_eq(matrice[2][1], 0);
    cr_assert_eq(matrice[2][2], 1);
}
