/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** mutinf
*/

#include <stdlib.h>
#include "../../include/my.h"

char *delete01(char *str)
{
    int i = 0;

    str = my_revstr(str);
    for (; str[i] == '0' ; i++);
    str = &str[i];
    str = my_revstr(str);
    if (*str == '\0')
        return ("0");
    return (str);
}

char *mutinf_loop(char const *nb1, char const *nb2, char *result)
{
    int tmp = 0;
    int i = 0;
    int j = 0;

    for (i = 0 ; nb1[i] != '\0' ; i++) {
        for (j = 0 ; nb2[j] != '\0' ; j++) {
            tmp = ATN(nb1[i]) * ATN(nb2[j]) + tmp + ATN(result[j + i]);
            result[j + i] = NTA(tmp % 10);
            tmp /= 10;
        }
        result[j + i] = NTA(tmp);
        tmp = 0;
    }
    result[i + j] = '\0';
    result = delete01(result);
    return (result);
}

char *mutinf_init(char const *nb1, char const *nb2, int signe)
{
    int len = my_strlen(nb1) + my_strlen(nb2);
    char *result = malloc(sizeof(char) * (len + signe + 1));
    char *nbr1 = my_revstr(my_strdup(nb1));
    char *nbr2 = my_revstr(my_strdup(nb2));

    test_malloc(result);
    result = my_memset(result, len, '0');
    result = mutinf_loop(nbr1, nbr2, result);
    if (signe && !(*result == '0' && result[1] == '\0')) {
        result[my_strlen(result) + 1] = '\0';
        result[my_strlen(result)] = '-';
    }
    return (my_revstr(result));
}

char *mutinf(char const *nb1, char const *nb2)
{
    if (*nb1 == '-' && *nb2 == '-')
        return (mutinf_init(&nb1[1], &nb2[1], 0));
    if (*nb1 == '-')
        return (mutinf_init(&nb1[1], nb2, 1));
    else if (*nb2 == '-')
        return (mutinf_init(nb1, &nb2[1], 1));
    else
        return (mutinf_init(nb1, nb2, 0));
}
