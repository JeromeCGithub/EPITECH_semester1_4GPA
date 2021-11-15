/*
** EPITECH PROJECT, 2019
** my_cat
** File description:
** my cat
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int my_strlen(char const *str);

void user_chiant(void)
{
    int error = 0;
    char buff[4097];

    error = read(0, &buff, 4096);
    while (error > 0)
    {
        write(1, &buff, error);
        error = read(1, &buff, error);
    }
}

void write_error(char **av, int j)
{
    write(2, "cat: ", 5);
    for (int i = 0 ; i <= my_strlen(av[j]) ; i++)
        write(2, &av[j][i], 1);
    write(2, ": ", 2);
    write(2, "No such file or directory\n", 26);
}

void printt(char **av, int j)
{
    for (int i = 0 ; i <= my_strlen(av[j]) ; i++)
        write(2, &av[j][i], 1);
}

int r_w(int *fd, int j, char **av)
{
    char buff[4096];
    int size = 1;

    while (size > 0) {
        size = read(*fd, &buff, 1);
        if (errno == EISDIR) {
            write(2, "cat: ", 5);
            printt(av, j);
            write(2, ": Is a directory\n", 17);
            return (84);
        }
        write(1, &buff, size);
    }
    return (0);
}

int main(int ac, char **av)
{
    int fd;
    char buff[4097];
    int size = 1;
    int the_return = 0;

    if (ac < 2) {
        user_chiant();
        return (0);
    }
    for (int i = 1 ; i < ac ; i++) {
        fd = open(av[i], O_RDONLY);
        if (errno == 2) {
            write_error(av, i);
            return (84);
        }
        the_return = r_w(&fd, i, av);
        close(fd);
    }
    return (the_return);
}
