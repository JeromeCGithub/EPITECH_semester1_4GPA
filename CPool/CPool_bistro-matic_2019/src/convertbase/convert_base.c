/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** convert_base
*/

#include "../../include/my.h"

int test_base10(char const *base_nb)
{
    char *index = "0123456789";
    int i = 0;

    if (my_strlen(base_nb) != 10)
        return (0);
    for (; base_nb[i] == index[i] && base_nb[i] != '\0' ; i++);
    if (i == 10)
        return (1);
    return (0);
}

char *convert_base_to10(char const *str, char const *base_from)
{
    char *str_from = my_revstr(my_strdup(str));
    char *result = malloc(sizeof(char) * 2);
    char *base = my_nbtostr(my_strlen(base_from));
    char *puissance = malloc(sizeof(char) * 2);

    test_malloc(result);
    test_malloc(base);
    test_malloc(puissance);
    puissance = my_memset(puissance, 1, '1');
    result = my_memset(result, 1, '0');
    for (int i = 0 ; str[i] != '\0' ; i++) {
        result = addinf(result,
                        mutinf(puissance, my_nbtostr(ATN(str_from[i]))));
        puissance = mutinf(puissance, base);
    }
    return (result);
}

char *convert_to10(char const *calcul, char const *base_from)
{
    char *result = malloc(sizeof(char) * (my_strlen(calcul) + 1));
    int n = 0;

    if (test_base10(base_from))
        return (my_strdup(calcul));
    test_malloc(result);
    for (int i = 0 ; calcul[i] != '\0' ;) {
        if (is_operand(calcul[i]) || calcul[i] == '(' || calcul[i] == ')') {
            result = my_strndog(result, &calcul[i], 1);
            i++;
            continue;
        }
        for (n = 0 ; calcul[i + n] >= '0' && calcul[i + n] != '\0'; n++);
        result = my_strcat(result, convert_base_to10(my_strndup(&calcul[i], n),
                                                    base_from));
        i += n;
    }
    return (result);
}
