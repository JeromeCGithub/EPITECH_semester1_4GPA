/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** String to word.
*/

#include <minishell.h>

int count_word(char const *str)
{
    int counter = 0;

    for (int i = 0 ; str[i] ; i++)
        if (str[i] != '\t' && str[i] != ' '
            && (i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t'))
            counter++;
    return (counter);
}

char **my_str_to_word_array(char const *str)
{
    int j = 0;
    int nb_mot = 0;
    int nb_char = 0;
    char **array = malloc(sizeof(char *) * (count_word(str) + 1));

    for (int i = 0 ; str[i] ; i++) {
        if (!(str[i] != '\t' && str[i] != ' '
            && (i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t')))
            continue;
        for (j = i, nb_char = 0 ; str[j] != '\t' && str[j] != ' '
                && str[j] ; nb_char++, j++);
        array[nb_mot] = malloc(sizeof(char) * (nb_char + 1));
        for (j = 0, nb_char = i ; str[nb_char] != '\t' && str[nb_char] != ' ' && str[nb_char] ; nb_char++, j++)
            array[nb_mot][j] = str[nb_char];
        array[nb_mot][j] = '\0';
        nb_mot++;
    }
    array[nb_mot] = NULL;
    return (array);
}
