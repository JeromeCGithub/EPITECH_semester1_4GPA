/*
** EPITECH PROJECT, 2020
** my ls
** File description:
** display owner usre
*/

#include <my.h>

void display_owner_user(struct stat sb)
{
    struct group *user = getgrgid(sb.st_gid);
    struct passwd *owner = getpwuid(sb.st_uid);

    if (user == NULL || owner == NULL)
        return;
    my_putstr(owner->pw_name);
    write(1, " ", 1);
    my_putstr(user->gr_name);
    write(1, " ", 1);
}
