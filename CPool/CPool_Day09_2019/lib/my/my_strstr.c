/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** Function my_strstr.
*/

#include <stddef.h>

int is_complete_string(char *str, char const *to_find, int i, int *ptr)
{
    int j = 0;

    *ptr = i;
    while (to_find[j] != '\0')
    {
        if (str[i] != to_find[j])
            return (0);
        i++;
        j++;
    }
    return (1);
}

char *my_strstr(char *str, char const *to_find)
{
    int result = 0;
    int ptr = 0;

    if (to_find[0] == '\0')
        return (&str[0]);
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] == to_find[0])
            result = is_complete_string(str, to_find, i, &ptr);
        if (result == 1)
            return (&str[ptr]);
    }
    return (NULL);
}
