/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** subinf
*/

#include <stdlib.h>
#include "../../include/my.h"

static char *del0(char *result)
{
    int j = 0;

    result = my_revstr(result);
    for (; result[j] == '0' ; j++);
    result = my_revstr(result);
    result[my_strlen(result) - j] = '\0';
    if (*result == '\0') {
        result[0] = '0';
        result[1] = '\0';
    }
    return (result);
}

static char *fill_sub(char *result, int *i, int *temp, char *nb)
{
    for (; nb[*i] != '\0' ; (*i)++) {
        *temp = ATN(nb[*i]) - *temp;
        if (*temp < 0) {
            *temp += 10;
            result[*i] = NTA(*temp);
            *temp = 1;
            continue;
        }
        result[*i] = NTA(*temp);
        *temp = 0;
    }
    result = del0(result);
    return (result);
}

char *signe_subinf(char *result, int signe)
{
    if (signe && !(*result == '0' && result[1] == '\0')) {
        result[my_strlen(result) + 1] = '\0';
        result[my_strlen(result)] = '-';
    }
    return (result);
}

char *subinf_loop(char const *nbr1, char const *nbr2, int signe)
{
    char *result = malloc(sizeof(char) * (my_strlen(nbr1) + 1));
    char *nb1 = my_revstr(my_strdup(nbr1));
    char *nb2 = my_revstr(my_strdup(nbr2));
    int i = 0;
    int temp = 0;

    test_malloc(result);
    test_malloc(nb1);
    test_malloc(nb2);
    result = my_memset(result, my_strlen(nbr1), '0');
    for (; nb1[i] != '\0' && nb2[i] != '\0' ; i++) {
        result[i] = ATN(nb1[i]) - ATN(nb2[i]) - temp;
        temp = (result[i] < 0) ? (1) : (0);
        result[i] = (result[i] < 0) ? (NTA(result[i] + 10)) : (NTA(result[i]));
    }
    fill_sub(result, &i, &temp, nb1);
    signe_subinf(result, signe);
    return (my_revstr(result));
}

char *subinf(char const *nb1, char const *nb2)
{
    if (*nb1 == '-' && *nb2 == '-') {
        if (my_nbcmp(&nb1[1], &nb2[1]) != -1)
            return (subinf_loop(&nb1[1], &nb2[1], 1));
        else
            return (subinf_loop(&nb2[1], &nb1[1], 0));
    }
    if (*nb1 == '-')
        return (addinf_loop(&nb1[1], nb2, 1));
    if (*nb2 == '-')
        return (addinf_loop(nb1, &nb2[1], 0));
    if (my_nbcmp(nb1, nb2) != -1)
        return (subinf_loop(nb1, nb2, 0));
    else
        return (subinf_loop(nb2, nb1, 1));
}
