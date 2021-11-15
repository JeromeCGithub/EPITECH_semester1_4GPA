/*
** EPITECH PROJECT, 2020
** my ls
** File description:
** big rr flag manage
*/

#include <my.h>

void manage_big_r_print(char *to_list, size_t flag)
{
    if (flag & BIG_R_FLAG) {
        if (to_list[my_strlen(to_list) - 1] == '/')
            to_list[my_strlen(to_list) - 1] = '\0';
        my_putstr(my_strcat(to_list, ":\n"));
    }
}
