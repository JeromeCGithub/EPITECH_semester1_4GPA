/*
** EPITECH PROJECT, 2020
** my ls
** File description:
** test ls
*/

#include <my.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_ls, test1)
{
    char *av[] = {"./my_ls", "-t", "tests/test"};

    cr_redirect_stdout();
    my_ls(2, av, 0);
    cr_assert_stdout_eq_str("lol\n");
}

Test(my_ls, test2)
{
    char **av = malloc(sizeof(char *) * 2);

    av[0] = malloc(sizeof(char) * 1);
    av[1] = malloc(sizeof(char) * 3);
    av[1][0] = '-';
    av[1][1] = 'l';
    av[1][2] = '\0';
    cr_redirect_stdout();
    my_ls(2, av, 0);
}

Test(my_ls, test_take_flag)
{
    char str[] = "-lrtR";
    char str2[] = "-l";
    char str3[] = "-r";
    size_t flag1 = 0;
    size_t flag2 = 0;
    size_t flag3 = 0;

    check_flag(&flag1, str);
    check_flag(&flag2, str2);
    check_flag(&flag3, str3);
    cr_assert_eq(flag1, 15);
    cr_assert_eq(flag2, 1);
    cr_assert_eq(flag3, 2);
}

Test(my_ls, test4)
{
    char *av[] = {"./my_ls", ".", "-d"};

    cr_redirect_stdout();
    my_ls(3, av, 0);
    cr_assert_stdout_eq_str(".\n");
}

Test(my_ls, test6, .exit_code = 84)
{
    char *mol = malloc(sizeof(char) * 2);
    char **av;

    av = malloc(sizeof(char *) * 2);
    mol[0] = 'r';
    mol[1] = '\0';
    av[1] = mol;
    cr_redirect_stderr();
    my_ls(2, av, 0);
}
