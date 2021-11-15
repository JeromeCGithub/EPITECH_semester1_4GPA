/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** modify_matrice
*/

#include "../include/my.h"

Test(modify_matrice, test_translation)
{
    float **matrice = init_matrice();
    char *av[] = {"-t", "2", "-2"};

    translation(matrice, av);
    cr_assert_eq(matrice[0][0], 1);
    cr_assert_eq(matrice[0][1], 0);
    cr_assert_eq(matrice[0][2], 2);
    cr_assert_eq(matrice[1][0], 0);
    cr_assert_eq(matrice[1][1], 1);
    cr_assert_eq(matrice[1][2], -2);
    cr_assert_eq(matrice[2][0], 0);
    cr_assert_eq(matrice[2][1], 0);
    cr_assert_eq(matrice[2][2], 1);
}

Test(modify_matrice, test_scaling)
{
    float **matrice = init_matrice();
    char *av[] = {"-z", "2", "-2"};

    scaling(matrice, av);
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

Test(modify_matrice, test_rotation)
{
    float **matrice = init_matrice();
    char *av[] = {"-r", "90"};

    rotation(matrice, av);
    cr_assert_eq(matrice[0][1], -1);
    cr_assert_eq(matrice[0][2], 0);
    cr_assert_eq(matrice[1][0], 1);
    cr_assert_eq(matrice[1][2], 0);
    cr_assert_eq(matrice[2][0], 0);
    cr_assert_eq(matrice[2][1], 0);
    cr_assert_eq(matrice[2][2], 1);
}

Test(modify_matrice, test_reflection)
{
    float **matrice = init_matrice();
    char *av[] = {"-s", "270"};

    reflection(matrice, av);
    cr_assert_eq(matrice[0][0], -1);
    cr_assert_eq(matrice[1][1], 1);
    cr_assert_eq(matrice[1][2], 0);
    cr_assert_eq(matrice[2][0], 0);
    cr_assert_eq(matrice[2][1], 0);
    cr_assert_eq(matrice[2][2], 1);
}
