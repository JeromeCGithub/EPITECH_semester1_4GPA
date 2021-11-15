/*
** EPITECH PROJECT, 2020
** my ls
** File description:
** main
*/

#include <my.h>

void is_next_dir(char **av, int indice)
{
    DIR *dir_test;
    static int next = 1;

    if ((next == 0 && (dir_test = opendir(av[0])) != NULL) || indice) {
        write(1, av[0], my_strlen(av[0]));
        write(1, ":\n", 2);
        closedir(dir_test);
        return;
    }
    for (int i = 1 ; av[i] && next ; i++)
        if (av[i][0] != '-' && (dir_test = opendir(av[0])) != NULL) {
            write(1, av[0], my_strlen(av[0]));
            write(1, ":\n", 2);
            next = 0;
            closedir(dir_test);
        }
}

void is_last(char **av)
{
    for (int i = 1 ; av[i] ; i++)
        if (av[i][0] != '-')
            write(1, "\n", 1);
}

int is_only_flag(char **av)
{
    for (int i = 1 ; av[i] ; i++)
        if (av[i][0] != '-')
            return (0);
    return (1);
}

void d_flag_manage(char **av, size_t flag, int ac)
{
    struct stat sb;
    struct dirent *content;
    DIR *directory;
    int i = 0;

    (flag & LITTLE_R_FLAG) ? (i = ac) : (i = 0);
    while (i >= 0 && av[i]) {
        if ((directory = opendir(av[i])) && !(flag & L_FLAG)) {
            is_existing(directory, av[i]);
            my_putstr(my_strcat(av[i], "\n"));
        }
        else if ((directory = opendir(av[i])) && (flag & L_FLAG)) {
            is_existing(directory, av[i]);
            lstat(av[i], &sb);
            display_line(sb, 0);
            my_putstr(my_strcat(av[i], "\n"));
        }
        (flag & LITTLE_R_FLAG) ? i-- : i++;
    }
}

void my_ls(int ac, char **av, int indice)
{
    DIR *dir;
    size_t flag = take_flag(av);

    av = pre_sort(ac, av);
    if (flag & D_FLAG) {
        if (ac == 2)
            write(1, ".\n", 2);
        d_flag_manage(av, flag, ac - 1);
        return;
    }
    if (ac == 1 || is_only_flag(av))
        listing(".", flag);
    for (int i = 1 ; av[i] ; i++) {
        if (av[i][0] != '-') {
            is_next_dir(&av[i], indice);
            listing(av[i], flag);
            is_last(&av[i]);
        }
    }
}
