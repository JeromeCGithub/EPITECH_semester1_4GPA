/*
** EPITECH PROJECT, 2019
** test_my_str_isprintable
** File description:
** Test if my str is printable is functionnal.
*/

#include <criterion/criterion.h>

int my_str_isprintable(char const *str);

Test(my_str_isprintable, check_if_isprintable)
{
    cr_assert(my_str_isprintable("dsai0312''") == 1);
}

Test(my_str_isprintable, check_two)
{
    cr_assert(my_str_isprintable("\t") == 0);
}
