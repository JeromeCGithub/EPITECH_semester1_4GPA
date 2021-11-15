/*
** EPITECH PROJECT, 2019
** 103cipher
** File description:
** my.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

typedef struct tab {
    int lines;
    int columns;
    double **matrice;
} tab_t;

static const char FILE_HELP[] = "help";

int find_key_size(char const *str);
void help(char const *);
int my_strcmp(char const *, char const *);
int my_strlen(char const *);
void encode(char const *, char const *);
void decode(char const *, char const *);
tab_t *create_tab(int, int);
void display_matrice(tab_t *);
tab_t *multiply_matrice(tab_t *, tab_t *);
void destroy_tab(tab_t *);
