/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** read it
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <curses.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *read_it(char const *str)
{
    struct stat sb;
    char *buff;
    int fd;

    stat(str, &sb);
    buff = malloc(sizeof(char) * sb.st_size + 2);
    fd = open(str, O_RDONLY);
    if (buff == NULL || read(fd, buff, sb.st_size) <= 0)
        exit(84);
    close(fd);
    buff[sb.st_size] = '\0';
    return (buff);
}
