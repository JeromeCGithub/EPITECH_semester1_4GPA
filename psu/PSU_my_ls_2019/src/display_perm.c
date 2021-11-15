/*
** EPITECH PROJECT, 2020
** my ls
** File description:
** display perm
*/

#include <my.h>

void display_perm(struct stat sb)
{
    (sb.st_mode & S_IRUSR) ? write(1, "r", 1) : write(1, "-", 1);
    (sb.st_mode & S_IWUSR) ? write(1, "w", 1) : write(1, "-", 1);
    (sb.st_mode & S_IXUSR) ? write(1, "x", 1) : write(1, "-", 1);
    (sb.st_mode & S_IRGRP) ? write(1, "r", 1) : write(1, "-", 1);
    (sb.st_mode & S_IWGRP) ? write(1, "w", 1) : write(1, "-", 1);
    (sb.st_mode & S_IXGRP) ? write(1, "x", 1) : write(1, "-", 1);
    (sb.st_mode & S_IROTH) ? write(1, "r", 1) : write(1, "-", 1);
    (sb.st_mode & S_IWOTH) ? write(1, "w", 1) : write(1, "-", 1);
    if (sb.st_mode & S_ISVTX) {
        if (sb.st_mode & S_IXOTH)
            write(1, "t", 1);
        else
            write(1, "T", 1);
    }
    else if (sb.st_mode & S_IXOTH)
        write(1, "x", 1);
    else
        write(1, "-", 1);
    write(1, ". ", 2);
}
