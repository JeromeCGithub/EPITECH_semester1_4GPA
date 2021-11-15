/*
** EPITECH PROJECT, 2020
** my ls
** File description:
** display ll
*/

#include <my.h>

void display_type2(struct stat sb)
{
    switch (sb.st_mode & S_IFMT) {
    case S_IFCHR:
        write(1, "c", 1);
        break;
    case S_IFIFO:
        write(1, "p", 1);
    }
}

void display_type(struct stat sb)
{
    switch (sb.st_mode & S_IFMT) {
    case S_IFDIR:
        write(1, "d", 1);
        break;
    case S_IFSOCK:
        write(1, "s", 1);
        break;
    case S_IFLNK:
        write(1, "l", 1);
        break;
    case S_IFREG:
        write(1, "-", 1);
        break;
    case S_IFBLK:
        write(1, "b", 1);
        break;
    }
    display_type2(sb);
}

void display_line(struct stat sb, int indice)
{
    display_type(sb);
    display_perm(sb);
    my_put_nbr(sb.st_nlink);
    write(1, " ", 1);
    display_owner_user(sb);
    if (major(sb.st_rdev) == 0 && minor(sb.st_rdev) == 0) {
        my_put_nbr(sb.st_size);
        write(1, " ", 1);
    }
    else {
        if (major(sb.st_rdev) > 0) {
            my_put_nbr(major(sb.st_rdev));
            write(1, ", ", 2);
        }
        else
            write(1, " ", 1);
        my_put_nbr(minor(sb.st_rdev));
        write(1, " ", 1);
    }
    print_time(ctime(&sb.st_mtim.tv_sec));
}

void print_total(content_list_t *content_list)
{
    struct stat sb;
    int total = 0;
    content_list_t *my_list = content_list;

    while (my_list) {
        if (my_list->content->d_name[0] != '.') {
            lstat(my_list->path, &sb);
            total += sb.st_blocks;
        }
        my_list = my_list->next;
    }
    write(1, "total ", 6);
    my_put_nbr(total / 2);
    write(1, "\n", 1);
}

void display_ll(content_list_t *content_list, size_t const flag)
{
    struct stat stat_buff;
    content_list_t *my_list = content_list;

    if (my_list) {
        if (flag & LITTLE_R_FLAG)
            display_ll(my_list->next, flag);
        if (my_list->content->d_name[0] != '.') {
            lstat(my_list->path, &stat_buff);
            display_line(stat_buff,
                        (my_strcmp(my_list->path, "/dev") == 0) ? 1 : 0);
            display_it(my_list->content);
            display_readlink(my_list);
            my_putstr("\n");
        }
        if (!(flag & LITTLE_R_FLAG))
            display_ll(my_list->next, flag);
    }
}
