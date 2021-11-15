/*
** EPITECH PROJECT, 2019
** test_my_revstr
** File description:
** Test file of my rev str.
*/

#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr, reverse_string)
{
    char to_reverse[] = "new";

    my_revstr(to_reverse);
    cr_assert_str_eq(to_reverse, "wen");
}
