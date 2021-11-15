/*
** EPITECH PROJECT, 2020
** my ls
** File description:
** readlink
*/

#include <my.h>

void display_readlink(content_list_t *list)
{
    char buf[PATH_MAX];
    ssize_t buff_size = 0;
    size_t tmp = PATH_MAX;
    struct stat sb;

    lstat(list->path, &sb);
    if ((sb.st_mode & S_IFMT) == S_IFLNK) {
        my_putstr(" -> ");
        if ((buff_size = readlink(list->path, buf, tmp)) > 0) {
            for (int i = 0 ; i < buff_size ; i++)
                write(1, &buf[i], 1);
        }
    }
}
