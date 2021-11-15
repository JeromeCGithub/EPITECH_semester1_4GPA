/*
** EPITECH PROJECT, 2019
** test_my_strcapitalize
** File description:
** Test my project str capitalize
*/

#include <criterion/criterion.h>

char *my_strcapitalize(char *str);

Test(my_strcapitalize, capitalize_first_letter_of_words)
{
    char str[] = "hey, how are you? 42WORds forty-two; fifty+one";
    char string[] = "Hey, How Are You? 42words Forty-Two; Fifty+One";

    my_strcapitalize(str);
    cr_assert_str_eq(str, string);
}
