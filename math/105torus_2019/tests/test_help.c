/*
** EPITECH PROJECT, 2020
** 104intersection
** File description:
** test help
*/

#include <my.h>

Test(help, test1, .exit_code = 0)
{
    struct stat sb;
    int fd = open(FILE_HELP, O_RDONLY);
    char *buffer = NULL;

    help("-v");
    stat(FILE_HELP, &sb);
    buffer = malloc(sizeof(char) * sb.st_size);
    read(fd, buffer, sb.st_size);
    cr_redirect_stdout();
    help("-h");
    cr_assert_stdout_eq_str(buffer);
}
