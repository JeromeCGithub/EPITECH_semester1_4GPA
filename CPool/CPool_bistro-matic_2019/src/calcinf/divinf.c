/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** divinf
*/

#include <stdlib.h>
#include <unistd.h>
#include "../../include/my.h"
#include "../../include/bistromatic.h"

char *div_sign(char *result)
{
    result = my_revstr(result);
    result[my_strlen(result)] = '-';
    result[my_strlen(result) + 1] = '\0';
    result = my_revstr(result);
    return (result);
}

char *divinf_loop(char const *nb1, char const *nb2, int signe)
{
    char *result = malloc(sizeof(char) * (my_strlen(nb1) + 1));
    char *puissance = malloc(sizeof(char) * (my_strlen(nb1) + 1));

    test_malloc(result);
    test_malloc(puissance);
    puissance = my_memset(puissance, my_strlen(nb1), '\0');
    puissance[0] = '1';
    for (int i = 1 ; i < my_strlen(nb1) - my_strlen(nb2) ; i++)
        puissance = mutinf(puissance, "10");
    result = my_strdup(puissance);
    while (my_nbcmp(nb1, mutinf(nb2, result)) != -1) {
        result = addinf(result, puissance);
        if (my_nbcmp(nb1, mutinf(nb2, result)) == -1 && puissance[1] != '\0') {
            result = subinf(result, puissance);
            puissance = my_strndup(puissance, my_strlen(puissance) - 1);
        }
    }
    result = subinf(result, "1");
    (signe) ? (result = div_sign(result)) : result;
    return (result);
}

char *divinf(char const *nb1, char const *nb2)
{
    if (*nb2 == '0') {
        my_putstr2(SYNTAX_ERROR_MSG);
        exit(84);
    }
    if (*nb1 == '-' && *nb2 == '-') {
        if (my_nbcmp(&nb1[1], &nb2[1]) == -1)
            return ("0");
        return (divinf_loop(&nb1[1], &nb2[1], 0));
    }
    if (*nb1 == '-') {
        if (my_nbcmp(&nb1[1], nb2) == -1)
            return ("0");
        return (divinf_loop(&nb1[1], nb2, 1));
    }
    if (*nb2 == '-') {
        if (my_nbcmp(nb1, &nb2[1]) == -1)
            return ("0");
        return (divinf_loop(nb1, &nb2[1], 1));
    }
    return (divinf_loop(nb1, nb2, 0));
}
