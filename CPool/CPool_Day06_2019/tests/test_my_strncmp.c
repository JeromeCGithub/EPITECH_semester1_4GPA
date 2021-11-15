/*
** EPITECH PROJECT, 2019
** test_my_strncmp
** File description:
** Test my str n cmp.
*/

#include <criterion/criterion.h>

int my_strncmp(char const *s1, char const *s2, int n);

Test(my_strncmp, test_strncmp)
{
    cr_assert(my_strncmp("dsb", "dsa", 3) == 1);
}

Test(my_strncmp, test2)
{
    cr_assert(my_strncmp("std", "std", 3) == 0);
}

Test(my_strncmp, test3)
{
    cr_assert(my_strncmp("stda", "stdf", 4) == -1);
}
