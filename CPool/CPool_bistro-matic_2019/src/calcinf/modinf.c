/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** modinf
*/

#include <stdlib.h>
#include <unistd.h>
#include "../../include/my.h"
#include "../../include/bistromatic.h"

char *modinf(char const *nb1, char const *nb2)
{
    if (*nb2 == '0') {
        my_putstr2(SYNTAX_ERROR_MSG);
        exit(84);
    }
    if (*nb1 == '-' && *nb2 == '-')
        if (my_nbcmp(&nb1[1], &nb2[1]) == -1)
            return (my_strdup(nb2));
    if (*nb1 == '-')
        if (my_nbcmp(&nb1[1], nb2) == -1)
            return (my_strdup(nb2));
    if (*nb2 == '-')
        if (my_nbcmp(nb1, &nb2[1]) == -1)
            return (my_strdup(nb2));
    return (subinf(nb1, mutinf(divinf(nb1, nb2), nb2)));
}
