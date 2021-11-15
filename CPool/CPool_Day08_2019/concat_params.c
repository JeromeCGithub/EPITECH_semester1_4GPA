/*
** EPITECH PROJECT, 2019
** concat_params
** File description:
** print command line in argument dynamicly.
*/

#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    int len = 0;
    char *str = NULL;
    int k = 0;

    for (int i = 0 ; i < argc ; i++) {
        for (int j = 0 ; argv[i][j] != '\0' ; j++)
            len++;
    }
    str = malloc(sizeof(char) * (len + argc - 1));
    for (int i = 0 ; i < argc ; i++) {
        for (int j = 0 ; argv[i][j] != '\0' ; j++) {
            str[k] = argv[i][j];
            k++;
        }
        str[k] = '\n';
        k++;
    }
    str[k - 1] = '\0';
    return (str);
}
