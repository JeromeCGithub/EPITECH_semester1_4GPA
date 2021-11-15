/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** addinf
*/

#include <stdlib.h>
#include "../../include/my.h"

char *fill_add(char const *nb, int *i, char *result, int *temp)
{
    for (; *i < my_strlen(nb) ; *temp /= 10, (*i)++) {
        *temp = ATN(nb[*i]) + *temp;
        result[*i] = NTA(*temp % 10);
    }
    return (result);
}

char *signe_addinf(char *result, int signe, int i)
{
    int j = 0;

    result = my_revstr(result);
    for (; result[j] == '0' ; j++);
    result = &result[j];
    result = my_revstr(result);
    if (*result == '\0') {
        result[0] = '0';
        result[1] = '\0';
    }
    if (signe) {
        for (; result[i] != '\0' ; i++);
        result[i] = '-';
        result[i + 1] = '\0';
    }
    return (result);
}

char *addinf_loop(char const *nbr1, char const *nbr2, int signe)
{
    int len = MAX_LEN(my_strlen(nbr1), my_strlen(nbr2));
    char *result = malloc(sizeof(char) * (len + signe + 1));
    int i = 0;
    int temp = 0;
    char *nb1 = my_revstr(my_strdup(nbr1));
    char *nb2 = my_revstr(my_strdup(nbr2));

    test_malloc(result);
    test_malloc(nb1);
    test_malloc(nb2);
    result = my_memset(result, len + 1, '0');
    for (; nb1[i] != '\0' && nb2[i] != '\0' ; i++, temp /= 10) {
        temp = ATN(nb1[i]) + ATN(nb2[i]) + temp;
        result[i] = NTA(temp % 10);
    }
    (my_strlen(nb1) - my_strlen(nb2) > 0) ?
        fill_add(nb1, &i, result, &temp) : fill_add(nb2, &i, result, &temp);
    result[i] = NTA(ATN(result[i]) + temp % 10);
    result = signe_addinf(result, signe, i);
    return (my_revstr(result));
}

char *addinf(char const *nb1, char const *nb2)
{
    if (*nb1 == '-' && *nb2 == '-')
        return (addinf_loop(&nb1[1], &nb2[1], 1));
    if (*nb1 == '-')
        if (my_nbcmp(&nb1[1], nb2) != -1)
            return (subinf_loop(&nb1[1], nb2, 1));
        else
            return (subinf_loop(nb2, &nb1[1], 0));
    if (*nb2 == '-')
        if (my_nbcmp(nb1, &nb2[1]) != -1)
            return (subinf_loop(nb1, &nb2[1], 0));
        else
            return (subinf_loop(&nb2[1], nb1, 1));
    return (addinf_loop(nb1, nb2, 0));
}
