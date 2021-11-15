/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** score gestion
*/

#include "../include/my.h"

int my_nblen(int score)
{
    int i = 0;

    while (score > 0) {
        score = score / 10;
        i++;
    }
    i++;
    return (i);
}

void manage_size_score(sfText *score_txt, int score, sfRenderWindow *window)
{
    int nb_len = my_nblen(score);
    sfVector2f position = convert_vector2f(window, 895, 115);

    if (nb_len > 2) {
        sfText_setPosition(score_txt, position);
    }
}

void manage_score(sfText *score_txt, int score, sfRenderWindow *window)
{
    int indice = 0;
    char *score_c = malloc(sizeof(char) * my_nblen(score) + 1);
    int i = 0;

    manage_size_score(score_txt, score, window);
    if (score == 0) {
        score_c[0] = '0';
        score_c[1] = '\0';
        indice = 1;
    }
    for (i = 0 ; score > 0 ; i++) {
        score_c[i] = score % 10 + '0';
        score = score / 10;
    }
    if (indice == 0) {
        score_c[i] = '\0';
        my_revstr(score_c);
    }
    sfText_setString(score_txt, score_c);
}
