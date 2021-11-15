/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** convert result into base
*/

#include "../../include/my.h"

static char *convert_str(char const *result_10, char const *base_nb, int signe)
{
    int len = 0;
    int i = 0;
    char *base = my_nbtostr(my_strlen(base_nb));
    char *resultbase;
    char *temp = my_strdup(result_10);

    for (; !(*temp == '0' && temp[1] == '\0') ; len++)
        temp = divinf(temp, base);
    resultbase = malloc(sizeof(char) * (len + 1 + signe));
    test_malloc(resultbase);
    temp = my_strdup(result_10);
    for (; !(*temp == '0' && temp[1] == '\0') ; i++) {
        resultbase[i] = my_getnbr(modinf(temp, base)) + '0';
        temp = divinf(temp, base);
    }
    resultbase[i] = '\0';
    for (i = 0 ; resultbase[i] != '\0' ; i++)
        resultbase[i] = base_nb[resultbase[i] - '0'];
    return (resultbase);
}

char *reconvert(char const *result_10,
                char const *base_nb,
                char const *base_op)
{
    char *result;

    if (test_base10(base_nb) && result_10[0] != '-')
        return (my_strdup(result_10));
    if (test_base10(base_nb) && result_10[0] == '-') {
        result = my_strdup(result_10);
        result[0] = base_op[3];
        return (result);
    }
    if (*result_10 == '-') {
        result = convert_str(&result_10[1], base_nb, 1);
        result[my_strlen(result) + 1] = '\0';
        result[my_strlen(result)] = base_op[3];
    } else
        result = convert_str(result_10, base_nb, 0);
    if (*result == '\0') {
        *result = '0';
        result[1] = '\0';
    }
    return (my_revstr(result));
}
