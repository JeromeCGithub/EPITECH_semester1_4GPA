/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** test unit bsq
*/

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(bsq, test_1)
{
    char *buff;
    int fd;
    char str[] = "tests/mouli_maps/intermediate_map_100_100";
    struct stat sb;

    cr_redirect_stdout();
    stat("tests/mouli_maps_solved/intermediate_map_100_100", &sb);
    buff = malloc(sizeof(char) * sb.st_size);
    fd = open("tests/mouli_maps_solved/intermediate_map_100_100", O_RDONLY);
    read(fd, buff, sb.st_size);
    bsq(2, str);
    cr_assert_stdout_eq_str(buff);
}

Test(bsq, test_2)
{
    char *buff;
    int fd;
    char str[] = "tests/mouli_maps/intermediate_map_187_187_empty";
    struct stat sb;

    cr_redirect_stdout();
    stat("tests/mouli_maps_solved/intermediate_map_187_187_empty", &sb);
    buff = malloc(sizeof(char) * sb.st_size);
    fd = open("tests/mouli_maps_solved/intermediate_map_187_187_empty",
                O_RDONLY);
    read(fd, buff, sb.st_size);
    bsq(2, str);
    cr_assert_stdout_eq_str(buff);
}

Test(bsq, test_3)
{
    char *buff;
    int fd;
    char str[] = "tests/mouli_maps/error6";
    struct stat sb;

    cr_redirect_stdout();
    stat("tests/mouli_maps_solved/error6", &sb);
    buff = malloc(sizeof(char) * sb.st_size);
    fd = open("tests/mouli_maps_solved/error6", O_RDONLY);
    read(fd, buff, sb.st_size);
    bsq(2, str);
    cr_assert_stdout_eq_str(buff);
}

Test(bsq, test_4)
{
    char *buff;
    int fd;
    char str[] = "tests/mouli_maps/intermediate_map_one_empty_box";
    struct stat sb;

    cr_redirect_stdout();
    stat("tests/mouli_maps_solved/intermediate_map_one_empty_box", &sb);
    buff = malloc(sizeof(char) * sb.st_size);
    fd = open("tests/mouli_maps_solved/intermediate_map_one_empty_box",
                O_RDONLY);
    read(fd, buff, sb.st_size);
    bsq(2, str);
    cr_assert_stdout_eq_str(buff);
}

Test(bsq, test_11)
{
    cr_assert_eq(bsq(2, "tests/mouli_maps/error3"), 0);
}
