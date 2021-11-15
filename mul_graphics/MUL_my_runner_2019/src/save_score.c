/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** save score
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

int my_strlen_moded(char *nb)
{
    int len = 0;

    for (len = 0 ; nb[len] != '.' ; len++);
    return (len + 1);
}

char *stock_nb(int score)
{
    int i = 0;
    char *number = malloc(sizeof(char) * (my_nblen(score) + 3));

    number[0] = '.';
    i += 1;
    for (int j = 0 ; j < my_nblen(score) ; j++) {
        number[i] = score % 10 + '0';
        score /= 10;
        i++;
    }
    number[i] = '-';
    number[i + 1] = '\0';
    number = my_revstr(number);
    return (number);
}

int char_to_nb(char *buff)
{
    int nb = 0;
    int i = 0;

    for (i = 0 ; buff[i] != '.' ; i++) {
        nb *= 10;
        nb += buff[i] - '0';
    }
    return (nb);
}

void save_score(int score)
{
    int nb;
    int fd;
    char *number;
    int tmp = 0;
    char buff[1025];

    number = stock_nb(score);
    fd = open("score.txt", O_RDWR);
    nb = read(fd, buff, 1024);
    buff[nb] = '\0';
    for (int i = 0 ; buff[i] != '\0' ; i++)
        if (buff[i] == '-' && tmp < char_to_nb(&buff[i + 1]))
            tmp = char_to_nb(&buff[i + 1]);
    if (score > tmp)
        write(fd, number, my_strlen_moded(number));
    close(fd);
}
