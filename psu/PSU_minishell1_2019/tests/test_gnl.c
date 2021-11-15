/*
** EPITECH PROJECT, 2020
** gnl
** File description:
** test gnl
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd);

Test(gnl, test_gnl1)
{
    int fd = open("tests/files_test/file1", O_RDONLY);

    cr_assert_str_eq(get_next_line(fd), "bonjour");
    cr_assert_str_eq(get_next_line(fd), "Test");
    cr_assert_str_eq(get_next_line(fd), "123");
    cr_assert_str_eq(get_next_line(fd), "\0");
    close(fd);
}

Test(gnl, test_gnl2)
{
    int fd = open("tests/files_test/file2", O_RDONLY);

    cr_assert_eq(get_next_line(fd), NULL);
    close(fd);
}

Test(gnl, test_gnl3)
{
    int fd = open("tests/files_test/file3", O_RDONLY);

    cr_assert_str_eq(get_next_line(fd), "lol");
    close(fd);
}

Test(gnl, test_gnl4)
{
    int fd = open("tests/files_test/file4", O_RDONLY);

    cr_assert_eq(get_next_line(fd), NULL);
    close(fd);
}
