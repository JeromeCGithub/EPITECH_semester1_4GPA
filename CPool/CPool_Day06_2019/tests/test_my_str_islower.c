/*
** EPITECH PROJECT, 2019
** test_my_str_islower
** File description:
** Test my is lower.
*/

#include <criterion/criterion.h>

int my_str_islower(char const *str);

Test(my_str_islower, check_my_str_islower)
{
    cr_assert(my_str_islower("dsa") == 1);
}

Test(my_str_islower, check_my_str_islower2)
{
    cr_assert(my_str_islower("DSA") == 0);
}
