/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** test bsq 2
*/

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(bsq, test_6)
{
    cr_redirect_stderr();
    bsq(10, "lodas");
    cr_assert_stderr_eq_str("USAGE : ./bsq file.txt\n");
}

Test(bsq, test_7)
{
    char *tab[] = {"..", "dwa"};
    cr_assert_eq(check_tab(tab), 1);
}

Test(bsq, test_8)
{
    cr_assert_eq(bsq(2, "tests/mouli_maps/vide"), 84);
}

Test(bsq, test_9)
{
    cr_assert_eq(bsq(2, "tests/mouli_maps/error"), 84);
}

Test(bsq, test_10)
{
    cr_assert_eq(bsq(2, "tests/mouli_maps/error2"), 84);
}
