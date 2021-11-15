/*
** EPITECH PROJECT, 2019
** test_my_str_isalpha
** File description:
** A test for my isalpha.
*/

#include <criterion/criterion.h>

int my_str_isalpha(char const *str);

Test(my_str_isalpha, need_1_or_0)
{
    cr_assert(my_str_isalpha("dwaSDAD") == 1);
}

Test(my_str_isalpha, need)
{
    cr_assert(my_str_isalpha("321") == 0);
}
