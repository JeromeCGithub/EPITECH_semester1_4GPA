/*
** EPITECH PROJECT, 2019
** 103cipher
** File description:
** cipher
*/

#include <my.h>

static int count_lines(char const *str, int key_size)
{
    int nb_char = my_strlen(str);
    int i = 0;

    for (; i * key_size < nb_char; i++);
    return (i);
}

static void fill_tab(tab_t *tab, char const *str)
{
    int k = 0;

    for (int i = 0; i < tab->lines; i++)
        for (int j = 0; j < tab->columns && str[k]; j++, k++)
            tab->matrice[i][j] = (double)str[k];
}

static void display_key(tab_t *key)
{
    printf("Key matrix:\n");
    for (int i = 0; i < key->lines; i++) {
        for (int j = 0; j < key->columns; j++)
            (j + 1 == key->columns) ?
                printf("%.0f", key->matrice[i][j]) :
                printf("%-8.0f", key->matrice[i][j]);            
        printf("\n");
    }
}

void encode(char const *str, char const *key_str)
{
    int key_size = find_key_size(key_str);
    tab_t *tab = create_tab(count_lines(str, key_size), key_size);
    tab_t *key = create_tab(key_size, key_size);

    fill_tab(tab, str);
    fill_tab(key, key_str);
    display_key(key);
    tab = multiply_matrice(tab, key);
    printf("\nEncrypted message:\n");
    for (int i = 0; i < tab->lines; i++)
        for (int j = 0; j < tab->columns; j++)
            (i + 1 == tab->lines && j + 1 == tab->columns) ?
                printf("%.0f", tab->matrice[i][j]) :
                printf("%.0f ", tab->matrice[i][j]);
    printf("\n");
}
