/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** high nb find
*/

#include <my.h>

void display_score(sfRenderWindow *window, pause_t *pause)
{
    sfRenderWindow_drawText(window, pause->score_txt, NULL);
    sfRenderWindow_drawText(window, pause->score_act, NULL);
    sfRenderWindow_drawText(window, pause->best_score_txt, NULL);
    sfRenderWindow_drawText(window, pause->pause_txt, NULL);
}

char *find_high_nb(char *buff)
{
    int j = 0;
    char *nb;
    int tmp = 0;
    int tmpne = 0;
    int len = 0;

    for (int i = 0 ; buff[i] != '\0' ; i++)
        if (buff[i] == '-'
            && char_to_nb(&buff[i + 1]) > char_to_nb(&buff[tmp]))
            tmp = i + 1;
    tmpne = tmp;
    for (len = 0 ; buff[tmp] != '.' ; tmp++)
        len++;
    nb = malloc(sizeof(char) * len + 1);
    for (j = 0 ; buff[tmpne] != '.' ; tmpne++) {
        nb[j] = buff[tmpne];
        j++;
    }
    nb[j] = '\0';
    return (nb);
}

char *nb_to_char(int score)
{
    int indice = 0;
    int i = 0;
    char *score_c = malloc(sizeof(char) * my_nblen(score) + 1);

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
    return (score_c);
}

void init_score(pause_t *pause, sfRenderWindow *window, int score)
{
    int fd;
    char buff[1025];
    int nb;

    fd = open("score.txt", O_RDONLY);
    nb = read(fd, buff, 1024);
    buff[nb] = '\0';
    pause->score_act = create_text("police/arial.ttf", 100,
                                convert_vector2f(window, 1250, 400),
                                nb_to_char(score));
    pause->pause_txt = create_text("police/arial.ttf", 100,
                                convert_vector2f(window, 600, 400),
                                "Actual score :");
    pause->best_score_txt = create_text
        ("police/arial.ttf", 100,
        convert_vector2f(window, 600, 500), "Best score :");
    pause->score_txt = create_text
        ("police/arial.ttf", 100,
        convert_vector2f(window, 1200, 500), find_high_nb(buff));
}
