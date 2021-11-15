/*
** EPITECH PROJECT, 2019
** 103cipher
** File description:
** help
*/

#include "include/my.h"

void help(char const *str)
{
    struct stat sb;
    int fd = open("help", O_RDONLY);
    char *buffer;

    if (!my_strcmp(str, "-h")) {
        stat(fd, &sb);
        buffer = malloc(sizeof(char) * sb.st_size);
        if (read(fd, buffer, sb.st_size) <= 0)
            exit(84);
        printf(buffer);
        free(buffer);
        exit(0);
    }
}
