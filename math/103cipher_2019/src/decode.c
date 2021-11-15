/*
** EPITECH PROJECT, 2019
** 103cipher
** File description:
** decode
*/

#include <my.h>

#define IS_NB(c) (c <= '9' && c >= '0') ? (1) : (0)

static int count_lines(char const *str, int key_size)
{
    int compteur = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            compteur++;
        }
    }
    return (compteur / key_size + 1);
}

tab_t *calc_com(tab_t *com, double **m)
{
    com->matrice[0][0] = m[1][1] * m[2][2] - m[2][1] * m[1][2];
    com->matrice[0][1] = m[0][2] * m[2][1] - m[2][2] * m[0][1];
    com->matrice[0][2] = m[0][1] * m[1][2] - m[1][1] * m[0][2];
    com->matrice[1][0] = m[1][2] * m[2][0] - m[2][2] * m[1][0];
    com->matrice[1][1] = m[0][0] * m[2][2] - m[2][0] * m[0][2];
    com->matrice[1][2] = m[0][2] * m[1][0] - m[1][2] * m[0][0];
    com->matrice[2][0] = m[1][0] * m[2][1] - m[2][0] * m[1][1];
    com->matrice[2][1] = m[0][1] * m[2][0] - m[2][1] * m[0][0];
    com->matrice[2][2] = m[0][0] * m[1][1] - m[1][0] * m[0][1];
    return (com);
}

int next_nb(char const *str, int *i)
{
    int j = 0;

    for (; str[j] && !IS_NB(str[j]) ; j++);
    for (; IS_NB(str[j]) ; j++);
    *i += j;
    return (atoi(str));
}

char ar(double nb)
{
    return ((char)(round(nb)));
}

void key_tree(int key_size, char const *key_str, char const *str)
{
    int lines = count_lines(str, key_size);
    tab_t *tab = create_tab(lines, key_size);
    tab_t *key = create_tab(key_size, key_size);
    tab_t *com = create_tab(key_size, key_size);
    double det = 0;
    int k = 0;
    int j = 0;
    int z = 0;

    for (int i = 0; i < key->lines; i++)
        for (j = 0; j < key->columns && key_str[k]; j++, k++)
            key->matrice[i][j] = (double)key_str[k];
    det = key->matrice[0][0] * (key->matrice[1][1] * key->matrice[2][2] - (key->matrice[1][2] * key->matrice[2][1]));
    det -= key->matrice[1][0] * (key->matrice[0][1] * key->matrice[2][2] - (key->matrice[2][1] * key->matrice[0][2]));
    det += key->matrice[2][0] * (key->matrice[0][1] * key->matrice[1][2] - (key->matrice[1][1] * key->matrice[0][2]));
    if (det == 0)
        exit(84);
    printf("Key matrix:\n");
    com = calc_com(com, key->matrice);
    for (int i = 0 ; i < com->lines ; i++) {
        for (int j = 0 ; j < com->columns ; j++) {
            com->matrice[i][j] /= det;
        }
    }
    for (int i = 0; i < key->lines; i++)
        printf("%-7.3f %-7.3f %.3f\n", com->matrice[i][0],
               com->matrice[i][1], com->matrice[i][2]);
    for (int i = 0 ; i < tab->lines ; i++)
        for (int j = 0; j < tab->columns; j++)
            tab->matrice[i][j] = next_nb(&str[z], &z);
    tab = multiply_matrice(tab, com);
    printf("\nDecrypted message:\n");
    for (int i = 0 ; i < tab->lines ; i++){
        for (int x = 0 ; x < tab->columns && tab->matrice[i][x] > 0 ; x++)
            printf("%c", ar(tab->matrice[i][x]));
    }
    printf("\n");
}

void key_two(int key_size, char const *str, char const *key_str)
{
    int lines = count_lines(str, key_size);
    tab_t *tab = create_tab(lines, key_size);
    tab_t *key = create_tab(key_size, key_size);
    double det = 0;
    double tmp = 0;
    int k = 0;
    int j = 0;
    int z = 0;
    
    for (int i = 0; i < key->lines; i++)
        for (j = 0; j < key->columns && key_str[k]; j++, k++)
            key->matrice[i][j] = (double)key_str[k];
    det = key->matrice[0][0] * key->matrice[1][1] - key->matrice[0][1] * key->matrice[1][0];
    if (det == 0)
        exit(84);
    printf("Key matrix:\n");
    tmp = key->matrice[1][1];
    key->matrice[1][1] = key->matrice[0][0];
    key->matrice[0][0] = tmp;
    key->matrice[1][0] = key->matrice[1][0] * (-1);
    key->matrice[0][1] = key->matrice[0][1] * (-1);
    for (int i = 0 ; i < key->lines ; i++) {
        for (int j = 0 ; j < key->columns ; j++) {
            key->matrice[i][j] /= det;
        }
    }
    for (int i = 0; i < key->lines; i++)
        printf("%-7.3f %-7.3f\n", key->matrice[i][0],
               key->matrice[i][1]);
    for (int i = 0 ; i < tab->lines ; i++)
        for (int j = 0; j < tab->columns ; j++)
            tab->matrice[i][j] = next_nb(&str[z], &z);
    tab = multiply_matrice(tab, key);
    printf("\nDecrypted message:\n");
    for (int i = 0 ; i < tab->lines ; i++) {
        for (int x = 0 ; x < tab->columns && tab->matrice[i][x] > 31 ; x++)
            printf("%c", ar(tab->matrice[i][x]));
    }
    printf("\n");
}

void key_one(int key_size, char const *str, char const *key_str)
{
    char *string = malloc(sizeof(char) * my_strlen(str));
    tab_t *key = create_tab(1, 1);
    int lines = count_lines(str, key_size);
    int i = 0;
    int z = 0;
    tab_t *tab = create_tab(lines, 1);

    key->matrice[0][0] = (double)key_str[0];
    key->matrice[0][0] = 1 / key->matrice[0][0];
    if (key->matrice[0][0] == 0)
        exit(84);
    printf("Key matrix:\n");
    for (int i = 0 ; i < tab->lines ; i++)
        for (int j = 0; j < tab->columns ; j++)
            tab->matrice[i][j] = next_nb(&str[z], &z);
    printf("%.3f\n", key->matrice[0][0]);
    printf("\nDecrypted message:\n");
    tab = multiply_matrice(tab, key);
    for (i = 0 ; i < lines ; i++)
        printf("%c", ar(tab->matrice[i][0]));
    printf("\n");
}

void decode(char const *str, char const *key_str)
{
    int key_size = find_key_size(key_str);

    switch (key_size) {
    case 1:
        key_one(key_size, str, key_str);
        break;
    case 2:
        key_two(key_size, str, key_str);
        break;
    case 3:
        key_tree(key_size, key_str, str);
        break;
    default:
        exit(0);
    }
}
