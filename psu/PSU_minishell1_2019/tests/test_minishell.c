/*
** EPITECH PROJECT, 2020
** test
** File description:
** minshell test
*/

#include <minishell.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(test_shell, test1)
{
    char **test = my_setenv(my_str_to_word_array("lol= ko="),
                            my_str_to_word_array("setenv lol 3"));
    char **test2 = my_unsetenv(my_str_to_word_array("lol= ko="), "lol");

    cr_assert_str_eq(test[0], "lol=3");
}

Test(test_shell, test2)
{
    int is_done = 0;
    char **test = my_setenv(my_str_to_word_array("lol= ko="),
                            my_str_to_word_array("setenv lol 3"));

    cr_redirect_stdout();
    cr_redirect_stderr();
    display_env(test);
    builtin_manage(my_str_to_word_array("cd lol"), test, &is_done);
}

Test(test_shell, test3)
{
    int is_done = 0;
    char **test = my_setenv(my_str_to_word_array("lol= ko="),
                            my_str_to_word_array("setenv lol 3"));

    cr_redirect_stdout();
    cr_redirect_stderr();
    builtin_manage(my_str_to_word_array("cd -"), test, &is_done);
}

Test(test_shell, test4)
{
    int is_done = 0;
    char **test = my_setenv(my_str_to_word_array("lol= ko="),
                            my_str_to_word_array("setenv lol 3"));

    cr_redirect_stdout();
    cr_redirect_stderr();
    builtin_manage(my_str_to_word_array("cd"), test, &is_done);
}

Test(test_shell, test5)
{
    char cpy_test[5];
    char **test = my_setenv(my_str_to_word_array("lol= ko= PATH=usr/test"),
                            my_str_to_word_array("setenv lol 3"));
    char **test2 = my_unsetenv(my_str_to_word_array("lol= ko="), "lol");

    my_get_env(test, "ls");
    cr_assert_eq(my_strlen("test10"), 6);
    my_strcpy(cpy_test, cpy_test);
}
