/*
** EPITECH PROJECT, 2019
** test_my_ststr
** File description:
** Test my program.
*/

#include <criterion/criterion.h>

char *my_strstr(char *str, char const *to_find);

Test(my_strstr, find_and_display_character)
{
    char str[] = "salut";
    char const to_find[] = "l";

    my_strstr(str, to_find);
    cr_assert_str_eq(my_strstr(str, to_find), "lut");
}
