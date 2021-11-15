/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** main of the bsq
*/

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/my.h"

int check_tab(char **tab)
{
    int value = 0;

    for (int i = 0 ; tab[i] != 0 ; i++) {
        for (int j = 0 ; tab[i][j] != '\0' && tab[i][j] != '\n'; j++) {
            (tab[i][j] != '.' && tab[i][j] != 'o') ? value = 1 : value;
        }
    }
    return (value);
}

char **complete_tab2(int collumn, char **tab, char *buff, int line)
{
    int p = 0;
    int j = 0;
    int i = 0;

    for ( i = 0 ; i < line ; i++) {
        tab[i] = malloc(sizeof(char) * (collumn + 1));
        if (tab[i] == NULL)
            return (NULL);
        for (p = 0 ; buff[j] != '\n' && buff[j] != '\0' ; j++) {
            tab[i][p] = buff[j];
            p++;
        }
        tab[i][p] = '\0';
        j++;
    }
    tab[i] = '\0';
    return (tab);
}

char **complete_tab(int line, char *buff)
{
    int col = 0;
    char **tab;

    tab = malloc(sizeof(char *) * (line + 2));
    if (tab == NULL)
        return (NULL);
    tab[line + 1] = 0;
    for (col = 0 ; buff[col] != '\n' && buff[col] != '\0'; col++);
    tab = complete_tab2(col, tab, buff, line);
    if (check_tab(tab) == 1)
        return (NULL);
    return (tab);
}

char **fs_open_file(char const *file)
{
    struct stat sb;
    char **tab;
    int fd;
    char *buff;
    int line;
    int comp = 0;

    stat(file, &sb);
    fd = open(file, O_RDONLY);
    buff = malloc(sizeof(char) * ((int)sb.st_size + 2));
    if (buff == NULL || read(fd, buff, sb.st_size) <= 0)
        return (NULL);
    buff[sb.st_size] = '\0';
    if ((line = my_getnbr(buff)) <= 0)
        return (NULL);
    for (comp = 0 ; buff[comp] != '\n' && buff[comp] != '\0' ; comp++);
    tab = complete_tab(line, &buff[comp + 1]);
    close(fd);
    free(buff);
    return (tab);
}

int main(int ac, char **av)
{
    char **tab;
    int **tab_int;

    if (ac != 2) {
        my_putstr2("USAGE : ./bsq file.txt\n");
        return (84);
    }
    tab = fs_open_file(av[1]);
    if (tab == NULL)
        return (84);
    tab_int = input_tabint(tab);
    if (tab_int == NULL)
        return (84);
    tab_int = find_best_square(tab_int);
    change_tab(tab, tab_int);
    free_all(tab, tab_int);
    return (0);
}
