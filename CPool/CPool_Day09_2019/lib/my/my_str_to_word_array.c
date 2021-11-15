/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** String to word.
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src);

int my_strlen(char const *str);

int count_number_word(char *new_str)
{
    int number_of_word = 0;

    for (int i = 0 ; new_str[i] != '\0' ; i++)
    {
        if (new_str[i] != '*' && (new_str[i - 1] == '*' || i == 0))
            number_of_word++;
    }
    return (number_of_word);
}

char *remplace_character(char const *str)
{
    char *new_str = malloc(sizeof(char) * my_strlen(str));

    new_str = my_strcpy(new_str, str);
    for (int i = 0 ; new_str[i] != '\0' ; i++)
    {
        if ((new_str[i] < 'a' || new_str[i] > 'z') &&
            (new_str[i] < 'A' || new_str[i] > 'Z') &&
            (new_str[i] < '0' || new_str[i] > '9'))
            new_str[i] = '*';
    }
    return (new_str);
}

char **input_this(char const *str, char **array, int number_of_word)
{
    int nb_mot = 0;
    int nb_char = 0;

    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] != '*') {
            array[nb_mot][nb_char] = str[i];
            nb_char++;
        }
        else if (nb_char > 0) {
            array[nb_mot][nb_char] = '\0';
            nb_mot++;
            nb_char = 0;
        }
    }
    if (array[nb_mot][0] == '\0')
        array[nb_mot] = 0;
    else
        array[nb_mot + 1] = 0;
}

char **my_str_to_word_array(char const *str)
{
    char * new_str = malloc(sizeof(char) * my_strlen(str));
    char **array = NULL;
    int nb_char = 0;
    int nb_mot = 0;
    int compteur_carac = 0;

    new_str = remplace_character(str);
    array = malloc(sizeof(char *) * (count_number_word(new_str) + 1));
    for (int i = 0 ; new_str[i] != '\0' ; i++) {
        if (new_str[i] != '*' && new_str[i + 1] != '\0')
            compteur_carac++;
        else if ((compteur_carac > 0)) {
            array[nb_mot] = malloc(sizeof(char) * (compteur_carac + 2));
            compteur_carac = 0;
            nb_mot++;
        }
    }
    array[nb_mot] = malloc(sizeof(char));
    input_this(new_str, array, count_number_word(new_str) + 1);
    return (array);
}
